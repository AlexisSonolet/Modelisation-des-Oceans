#include "./../headers/FastFourier.h"
#include <cmath>
#include <complex>
#include <stdbool.h>

using namespace std;


//ComplexVector<complex<double>> 
void fft(ComplexVector<complex<double>> &vect, bool inverse)
{
	int n = vect.size(); 
	complex<double> i;
	i = -1;
	i = sqrt(i);
	if(n<=1)
	{
		return;
	}
	else
	{
		if(!inverse)
		{
			// On choisit les éléments d'indice pairs et impairs
			ComplexVector<complex<double>>  even_vect = vect.get_even(); // Vecteur de complexes !
			ComplexVector<complex<double>>  odd_vect = vect.get_odd(); // Vecteur de complexes !
			//Appel récursif sur chacun des sous-tableaux
			fft(even_vect);
			fft(odd_vect);
			for(int k=0; k <= n/2 - 1; k++){
				complex<double> t = odd_vect.get(k) * exp((complex<double>)(-2 * M_PI * i * ((double)k/(double)n)));
				vect.set(k, even_vect.get(k) + t);
				vect.set(k+n/2, even_vect.get(k) - t);			
			}
		}

		else
		{
			// Transformée de Fourier Inverse
			ComplexVector<complex<double>> conjugate = vect.conjug();
			vect.set_v(conjugate.get_v());
			cout << vect.size() << endl;
			fft(vect, false);	
			ComplexVector<complex<double>> conjugate_2 = vect.conjug();
			vect.set_v(conjugate_2.get_v());
			vect /= n;
		}	

	
	}
}

