/*
 * window.h
 *
 *  Created on: 21 mars 2020
 *      Author: hyper
 */

#ifndef SRC_RENDERING_GLFW_WINDOW_H_
#define SRC_RENDERING_GLFW_WINDOW_H_

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "../Ocean.h"

#include <string>

class Window {
public:
	Window(int width, int height, std::string title);
	virtual ~Window();

	void mainloop(Ocean* ocean);

private:
	GLFWwindow* w;
};

#endif /* SRC_RENDERING_GLFW_WINDOW_H_ */
