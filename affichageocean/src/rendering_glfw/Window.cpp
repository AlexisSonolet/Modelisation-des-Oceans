/*
 * window.cpp
 *
 *  Created on: 21 mars 2020
 *      Author: hyper
 */

#include "Window.h"
#include "OceanRenderer.h"
#include "linmath.h"
#include <iostream>

static void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

static void framebuffer_size_callback(GLFWwindow* window, int width,
		int height) {
	glViewport(0, 0, width, height);
}

static double scroll;
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	scroll = yoffset;
}

static void updateView(GLFWwindow* window, float& d, float& theta, float& phi) {
	static double xpos = 0, ypos = 0;
	double new_xpos, new_ypos;

	glfwGetCursorPos(window, &new_xpos, &new_ypos);

	float dx = new_xpos - xpos;
	float dy = new_ypos - ypos;

	int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	if (state == GLFW_PRESS) {
		theta -= dx * 0.005f;
		phi += dy * 0.005f;

		if (phi < 0)
			phi = 0;
		if (phi > M_PI * 0.5f)
			phi = M_PI * 0.5f;
	}

	d *= (1.0f - scroll * 0.05f);
	scroll = 0;

	xpos = new_xpos;
	ypos = new_ypos;
}

Window::Window(int width, int height, std::string title) :
		w(NULL) {

	/* Initialize the library */
	if (!glfwInit())
		throw "Error while initializing GLFW";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_API, GLFW_TRUE);

	glfwWindowHint(GLFW_SAMPLES, 4);

	/* Create a windowed mode window and its OpenGL context */
	w = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (!w) {
		glfwTerminate();
		throw "Error while creating the window";
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(w);

	/* Load the opengl functions pointers */
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

	std::cout << glGetString(GL_VERSION) << std::endl;

	glfwSetErrorCallback(error_callback);
	glfwSetFramebufferSizeCallback(w, framebuffer_size_callback);
	glfwSetScrollCallback(w, scroll_callback);
}

Window::~Window() {
	glfwTerminate();
}

void Window::mainloop(Ocean* ocean) {
	OceanRenderer renderer;

	float theta = 0; // [0, 2*PI]
	float phi = M_PI / 4.0; // [0, PI/2]
	float d = 3;

	mat4x4 view;
	vec3 center = { 0.0f, 0.0f, 0.0f };
	vec3 up = { 0.0f, 1.0f, 0.0f };

	while (!glfwWindowShouldClose(this->w)) {
		/* Render here */
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		int width, height;
		glfwGetFramebufferSize(w, &width, &height);

		ocean->compute(1.0f / 60.0f);//mise à jour de la surface

		//on récupère un tableau des coordonnées des sommets (x, y, z)
		//(x, y, z) = (abscisse, ordonnées, hauteur)
		//avec
		//x = vertices[3*(j * nx + i) + 0];
		//y = vertices[3*(j * nx + i) + 1];
		//z = vertices[3*(j * nx + i) + 2];
		float* vertices = ocean->getVertices();

		uint32_t nx = ocean->getNx();
		uint32_t ny = ocean->getNy();

		updateView(w, d, theta, phi);
		vec3 eye = { d * sin(theta) * cos(phi), d * sin(phi), d * cos(theta)
				* cos(phi) };
		mat4x4_look_at(view, eye, center, up);

		renderer.draw(vertices, nx, ny, view, width, height);

		/* Swap front and back buffers */
		glfwSwapBuffers(this->w);

		/* Poll for and process events */
		glfwPollEvents();
	}
}

