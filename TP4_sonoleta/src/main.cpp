#include <iostream>
#include "./../headers/Height.h"
#include "./../headers/FastFourier.h"
#include "./../headers/PhilipsWave.h"
#include "./../headers/PhilipsWaveModel.h"
#include "./../test/test.h"
#include <complex>
#include <typeinfo>

using namespace std;

#include "./../headers/ComplexVector.h"
using Dvector = ComplexVector<double>;

int main() {
	test_fft();
	cout << "Test get height" << endl;
	test_get_height();	
	//cout << test_croiss_decroiss << endl;
	test_height();
    
	// Test de la fonction module (teste aussi la multiplication)
	Dvector dirr(2);
	dirr.set(0, 3);
	dirr.set(1, 4);
	cout << "Mod = " << module(&dirr) << endl;
    return 0;
}
