/*
 * main.cpp
 *
 *  Created on: 21 mars 2020
 *      OpenGL Template Author: Briac
 */


#include <string>
#include "Window.h"
#include "../../headers/ComplexVector.h"
#include "../../headers/PhilipsWaveModel.h"
using Dvector = ComplexVector<double>;


int main(void) {

	Window w(800, 600, std::string("Houle"));

	// === Paramètres ===
	double N = 20; // Discrétisation
	double M = 20; // Discrétisation
	double Lx = 10; // Bornes physiques
	double Ly = 10; // Bornes physiques
	double A = 1; // Amplitude
	double om = 0.5; // Fréquence ?
	double V = 1; // Vitesse du vent
	Dvector dir(2); // DIrection du vent
	dir.set(0, 1); // DIrection du vent
	dir.set(1, 1); // DIrection du vent

	PhilipsWaveModel wave(N, M, Lx, Ly, A, om, V, dir);
	Ocean ocean(Lx, Ly, N, M, &wave);

	w.mainloop(&ocean);


	return 0;
}

