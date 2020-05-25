/*
 * Renderer.cpp
 *
 *  Created on: 21 mars 2020
 *      Author: hyper
 */

#include "OceanRenderer.h"
#include <iostream>
#include <math.h>

OceanRenderer::OceanRenderer() :
		shader("../shaders/ocean.vs", "../shaders/ocean.gs", "../shaders/ocean.fs"), current_size(0), mesh_vao(
		NULL) {

	shader.bindVertexAttribute(0, "position");

	shader.finishInit();

	shader.start();
	shader.init_uniforms( { "projectionView", "transform" });
	shader.stop();
}

OceanRenderer::~OceanRenderer() {
	delete mesh_vao;
}

/**
 * Dessine le maillage de l'océan.
 * voir http://developer.download.nvidia.com/SDK/10/direct3d/Source/SolidWireframe/Doc/SolidWireframe.pdf
 * pour une explication du shader.
 * @param vertices
 * @param nx
 * @param ny
 * @param view
 * @param width
 * @param height
 */
void OceanRenderer::draw(float* vertices, uint32_t nx, uint32_t ny, mat4x4 view, int width, int height) {

	mat4x4 proj;
	mat4x4 projView;
	mat4x4 transform;

	mat4x4_perspective(proj, 90.0f * M_PI / 180.0f,
			(float) width / (float) height, 0.1f, 100.0f);

	mat4x4_mul(projView, proj, view);

	mat4x4_identity(transform);
	mat4x4_rotate(transform, transform, 1.0f, 0, 0, M_PI * 0.5f);

	updateVAO(vertices, nx, ny);

	shader.start();

	shader.loadMat4("projectionView", projView);
	shader.loadMat4("transform", transform);

	mesh_vao->bind();
	mesh_vao->bindAttribute(0);

	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	glDrawElements(GL_TRIANGLES, mesh_vao->getIndexCount(), GL_UNSIGNED_INT,
	NULL);

	mesh_vao->unbindAttribute(0);
	mesh_vao->unbind();

	shader.stop();

}

void OceanRenderer::updateVAO(float* vertices, uint32_t nx, uint32_t ny) {

	uint32_t size = (nx-1) * (ny -1);

	if (current_size != size || mesh_vao == NULL) {
		if (mesh_vao != NULL) {
			delete mesh_vao;
		}
		std::cout << "Init VAO..." << std::endl;

		mesh_vao = new VAO();
		mesh_vao->bind();

		uint32_t index_count;
		uint32_t* indices = buildIndices(index_count, nx, ny);
		mesh_vao->createIndexBuffer(indices, index_count);
		uint32_t data_length = nx * ny * 3;
		mesh_vao->createFloatAttribute(0, vertices, data_length, 3,
		GL_DYNAMIC_DRAW);
		mesh_vao->unbind();

		delete indices;
		current_size = size;

	} else {
		//std::cout << "Update VAO..." << std::endl;

		VBO* positions = mesh_vao->getAttributeVBOs()[0];
		positions->bind();
		positions->updateData(vertices, nx * ny * 3 * sizeof(float));
		positions->unbind();
	}

}

uint32_t* OceanRenderer::buildIndices(uint32_t& index_count, uint32_t nx,
		uint32_t ny) {
	index_count = (nx - 1) * (ny - 1) * 3 * 2;
	uint32_t* indices = new uint32_t[index_count];

	for (uint32_t y = 0; y < ny - 1; y++) {
		for (uint32_t x = 0; x < nx - 1; x++) {
			uint32_t quad = y * (nx - 1) + x;
			uint32_t top_left = y * nx + x;
			indices[6 * quad] = top_left;
			indices[6 * quad + 1] = top_left + nx;
			indices[6 * quad + 2] = top_left + nx + 1;

			indices[6 * quad + 3] = top_left;
			indices[6 * quad + 4] = top_left + nx + 1;
			indices[6 * quad + 5] = top_left + 1;
		}
	}

	return indices;
}

