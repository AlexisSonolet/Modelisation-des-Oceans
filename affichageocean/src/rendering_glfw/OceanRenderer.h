/*
 * Renderer.h
 *
 *  Created on: 21 mars 2020
 *      Author: hyper
 */

#ifndef SRC_RENDERING_GLFW_OCEANRENDERER_H_
#define SRC_RENDERING_GLFW_OCEANRENDERER_H_

#include "openglObjects.h"
#include <map>
#include <string>
#include "linmath.h"

class OceanRenderer {
public:
	OceanRenderer();
	virtual ~OceanRenderer();

	void draw(float* vertices, uint32_t nx, uint32_t ny, mat4x4 view, int width, int height);

private:
	Shader shader;
	uint32_t current_size;
	VAO* mesh_vao;

	void updateVAO(float* vertices, uint32_t nx, uint32_t ny);
	uint32_t* buildIndices(uint32_t& index_count, uint32_t nx, uint32_t ny);
};

#endif /* SRC_RENDERING_GLFW_OCEANRENDERER_H_ */
