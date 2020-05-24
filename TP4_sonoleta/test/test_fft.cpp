#include "./test.h"
#include "../headers/FastFourier.h"
#include <assert.h>
#include <iostream>
#include "./../headers/ComplexVector.h"

using Dvector = ComplexVector<double>;
using namespace std;

void test_fft()
{
	cout << "Test FFT" << endl;
	ComplexVector<complex<double>> test_fft(4);
	for(int i = 0; i < 4; i++)
	{
		test_fft.set(i, complex<double>(i+1, 0));
	}
	cout << "Avant la FFT : " << test_fft << endl;
	fft(test_fft);
	cout << "Apres la FFT : " << endl <<  test_fft << endl;
	cout << "Test IFFT croissant/decroissant" << endl;
	ComplexVector<complex<double>> test_croiss_decroiss(8);
	for(int i = 0; i < 8; i++){
		test_croiss_decroiss.set(i, complex<double>(i+1, 8-i));
	}
	cout << "Avant l' IFFT : " << endl << test_croiss_decroiss << endl;
	cout << "On applique la IFFT" << endl;
	fft(test_croiss_decroiss, true);
	cout << test_croiss_decroiss << endl;
	cout << "Comparer les résultats ci dessus avec ceux du site https://scistatcalc.blogspot.com/2013/12/fft-calculator.html" << endl;
}
