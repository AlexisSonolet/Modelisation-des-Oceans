#include "./test.h"
#include "../headers/Height.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_height()
{
	cout << "Test Classe Height" << endl;
	cout << "Création d'une surface" << endl;
	Height h(5, 5, 5, 5);
	for (int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			h.setValue(x, y, x+y);
		}
	}
	h.plot("./../");
	double value = h(2, 3);
	assert(value == 5);
	cout << "h(2,3) = " << value << endl;
	cout << "Test OK, utiliser Gnuplot ou Paraview sur le fichier plotting.dat généré" << endl;
}
