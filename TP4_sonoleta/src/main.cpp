#include <iostream>
#include "./../headers/Dvector.h"
#include "./../headers/Height.h"
#include "./../headers/ComplexVector.h"
#include "./../headers/FastFourier.h"
#include "./../headers/PhilipsWave.h"
#include "./../headers/PhilipsWaveModel.h"
#include <complex>
#include <typeinfo>
using namespace std;

int main() {
	cout << "Test IFFT croissant/decroissant" << endl;
	ComplexVector<complex<double>> test_croiss_decroiss(8);
	for(int i = 0; i < 8; i++)
	{
		test_croiss_decroiss.set(i, complex<double>(i+1, 8-i));
	}
	printf("On applique la IFFT\n");
	fft(test_croiss_decroiss, true);
	cout << "Test get height" << endl;
	Dvector dir(2);
	dir.set(0,2);
	dir.set(1,3);
	PhilipsWave test_vague(2,2,4,4,1,0.5,2, &dir);
	cout << test_vague.get_height(5) << endl;	
	
	
	cout << test_croiss_decroiss << endl;
	printf("Test Q5 (FFT d'une donnée bidimensionnelle stockée sous forme d'un tableau monodimensionnel\n");
	ComplexVector<complex<double>> points[2];

	cout << "Classe Height" << endl;
    cout << "1.1. Création d'une surface" << endl;
    Height h(5, 5, 5, 5);
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            h.setValue(x, y, x+y);
        }    
    }
    h.plot("./../");
    
    cout << "1.2. et du foncteur" << endl;
    double value = h(2, 3);
    cout << "h(2,3) = " << value << endl;

    // Question 2 : WaveModel
    cout << "Classe WaveModel" << endl;

    // Question 3 : Gerstner
    cout << "Classe GerstnerWave" << endl;
    return 0;
}
