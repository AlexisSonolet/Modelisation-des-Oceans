/*
 * main.cpp
 *
 *  Created on: 21 mars 2020
 *      Author: Briac
 */


#include <string>
#include "Window.h"

int main(void) {

	Window w(800, 600, std::string("Houle"));

	Ocean ocean;

	w.mainloop(&ocean);


	return 0;
}

