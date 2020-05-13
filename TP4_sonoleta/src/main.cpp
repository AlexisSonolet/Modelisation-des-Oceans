#include <iostream>
#include "./../headers/Dvector.h"
#include "./../headers/Height.h"
#include "./../headers/ComplexVector.h"
#include "./../headers/FastFourier.h"
#include <complex>
#include <typeinfo>
using namespace std;

int main() {
	
	cout << "Classe Height" << endl;
    cout << "1.1. Création d'une surface" << endl;
    Height h(5, 5, 5, 5);
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            h.setValue(x, y, x+y);
        }    
    }
    h.plot("./../");
    
    cout << "1.2. est du foncteur" << endl;
    double value = h(2, 3);
    cout << "h(2,3) = " << value << endl;

    // Question 2 : WaveModel
    cout << "Classe WaveModel" << endl;

    // Question 3 : Gerstner
    cout << "Classe GerstnerWave" << endl;
    return 0;
}
