/*
 * Ocean.h
 *
 *  Created on: 30 mars 2020
 *      Author: hyper
 */

#ifndef SRC_OCEAN_H_
#define SRC_OCEAN_H_

#include <stdint.h>
#include <math.h>

#include <GLFW/glfw3.h>

/**
 * Exemple de classe océan permettant de compiler le projet
 */
class Ocean {
public:
	Ocean();
	virtual ~Ocean();

	void compute(float dt) {

	}

	/**
	 * on récupère un tableau des coordonnées des sommets (x, y, z)
	 * (x, y, z) = (abscisse, ordonnées, hauteur)
	 * avec
	 * x = vertices[3*(j * nx + i) + 0];
	 * y = vertices[3*(j * nx + i) + 1];
	 * z = vertices[3*(j * nx + i) + 2];
	 *
	 * @return le tableau
	 */
	float* getVertices() {

		float lx = 40;
		float ly = 40;
		float time = glfwGetTime();

		for (uint32_t j = 0; j < getNx(); j++) {
			for (uint32_t i = 0; i < getNx(); i++) {
				float x = ((float) i / getNx() - 0.5f) * lx;
				float y = ((float) j / getNy() - 0.5f) * ly;
				float z = cos(sqrt(x*x + y*y) + time);

				vertices[3*(j * getNx() + i) + 0] = x;
				vertices[3*(j * getNx() + i) + 1] = y;
				vertices[3*(j * getNx() + i) + 2] = z;
			}
		}

		return vertices;
	}

	uint32_t getNx() {
		return 100;
	}
	uint32_t getNy() {
		return 100;
	}

private:
	float* vertices;

};

#endif /* SRC_OCEAN_H_ */
