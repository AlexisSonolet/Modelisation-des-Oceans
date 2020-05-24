#include "./test.h"
#include "../headers/FastFourier.h"
#include <assert.h>
#include <iostream>
#include "./../headers/ComplexVector.h"
#include "./../headers/PhilipsWave.h"

using Dvector = ComplexVector<double>;
using namespace std;

void test_get_height()
{
	Dvector dir(2);
	dir.set(0, 0.5);
	dir.set(1, 2.5);
	PhilipsWave test_vague(4, 4, 1, 1, 100, 0.5, 1, &dir);
	test_vague.show_attributes();
	for(double t = 0; t < 0.16; t+=0.05){
		cout << "T VAUT : " << t << endl;
		ComplexVector<complex<double>> height = test_vague.get_height(t);
		cout << "get_height "<< t << endl << height << endl;
	}	
}

