/*
 * Ocean.cpp
 *
 *  Created on: 30 mars 2020
 *      Author: hyper
 */

#include "Ocean.h"

Ocean::Ocean() : vertices(NULL) {

	vertices = new float[getNx() * getNy() * 3];

}

Ocean::~Ocean() {
	// TODO Auto-generated destructor stub
}

