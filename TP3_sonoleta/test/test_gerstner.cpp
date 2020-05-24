#include "./test.h"
#include "../headers/Dvector.h"
#include "../headers/Height.h"
#include "../headers/GerstnerWave.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_gerstner()
{
	cout << "Test Gerstner" << endl;
	Dvector dir(2);
	dir(0) = 3;
	dir(1) = 4;
	GerstnerWave test(2, 1, &dir, 0.4);
//	assert(module(&dir) == 5);
	cout << dir << endl;
	cout << module(&dir) << endl;
	cout << "Fréquence pour une onde de Gerstner avec A = 2, phi = 1 , dir = (3, 4) et f = 0.4 : " << compute_freq(&dir) << endl; 
}
