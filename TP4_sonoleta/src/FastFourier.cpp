#include "./../headers/FastFourier.h"
#include <cmath>
#include <complex>

using namespace std;

#define complex_i 1i


ComplexVector<complex<double>> fft(ComplexVector<complex<double>> &vect)
{
	int n = vect.size(); 
	if(n<=1)
	{
		return vect;
	}
	else
	{
		// On choisit les éléments d'indice pairs et impairs
		ComplexVector<complex<double>>  even_vect = vect.get_even(); // Vecteur de complexes !
		ComplexVector<complex<double>>  odd_vect = vect.get_odd(); // Vecteur de complexes !
		//Appel récursif sur chacun des sous-tableaux
		fft(even_vect);
		fft(odd_vect);
		for(int k=0; k <= n/2 - 1; k++){
			complex<double> t = odd_vect.get(k) * exp((complex<double>)(-2 * M_PI * 1.0i * (double)(k/n)));
			vect.set(k, even_vect.get(k) + t);
			vect.set(k+n/2, even_vect.get(k) - t);			
		}
	
	}
}

