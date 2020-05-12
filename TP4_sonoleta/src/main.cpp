#include <iostream>
#include "./../headers/Dvector.h"
#include "./../headers/Height.h"
#include "./../headers/ComplexVector.h"
#include "./../headers/FastFourier.h"
#include <complex>
#include <typeinfo>
using namespace std;

int main() {
	// test de even/odd
	//Dvector test(7);
	//test.fillRandomly();
	//test.display(cout);
	//Dvector test_even = test.get_even();
	//test_even.display(cout);
	//Dvector test_odd = test.get_odd();
	//test_odd.display(cout);
    // Question 1 : Height
    //cout << "Test FFT" << endl;
	// Using the tests at http://www.sccon.ca/sccon/fft/fft3.htm
	//ComplexVector<complex<double>> test_vect(8);
//	for(int i = 0; i < 5; i++){
	//test_vect.set(0, complex<double>(1.0,0.0));
		
//	}	
	//test_vect.display(cout);
	//cout << "We apply FFT and obtain" << endl;
	//fft(test_vect);
	//test_vect.display(cout);
	cout << "Test ComplexVector" << endl;
	ComplexVector <complex<double>> test_vect(8);
	test_vect.display(cout);
	printf("Type:\n");
	cout << typeid(test_vect).name() << endl;
	printf("TestFill\n");
	ComplexVector <complex<double>> test_vect_init(5, complex<double>(1,2)); 
	test_vect_init.display(cout);
	printf("TestAssignRandom\n");
	ComplexVector <complex<double>> test_vect_2(10);
	test_vect_2.fillRandomly();
	test_vect_2.display(cout);
	printf("Size of testAssign vector : %d\n", test_vect_2.size());
	printf("Test Recopie\n");
	ComplexVector <complex<double>> test_vect_copie(test_vect_2);
	printf("J'affiche la copie :\n");
	test_vect_copie.display(cout);
	printf("Check ==\n");
	printf(test_vect_copie == test_vect_2 ? "true\n" : "false\n");
	printf("Je modifie la copie\n");
	test_vect_copie.set(1, complex<double>(2,3));
	printf("J'affiche la copie:\n");
	test_vect_copie.display(cout);
	printf("On vérifie que l'original n'a pas changé:\n");
	test_vect_2.display(cout);	
	printf("Test Complex from file\n");
	ComplexVector<complex<double>> test_vect_3("./../src/tp4_test1.txt");
	test_vect_3.display(cout);
	printf("Test Basic operations:\n");
	printf("file - fillRandomly :\n");
	test_vect_3 -= test_vect_2;
	test_vect_3.display(cout);
	printf(" * 5 :\n");
	test_vect_3 *= 5;
	test_vect_3.display(cout);
	printf(" *= fillRandomly :\n");
	test_vect_3 *= test_vect_2;
	test_vect_3.display(cout);
	printf("Test print << \n");
	cout << test_vect_3 << endl;
	//printf("Test >> \n");
	//ComplexVector <complex<double>> test_vect_4(1);
	//cin >> test_vect_4;
	//cout << test_vect_4 << endl;
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
