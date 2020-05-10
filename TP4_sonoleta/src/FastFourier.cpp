#include "./../headers/FastFourier.h"
#include <complex>

using namespace std;

#define PI 3.1415926535
Dvector fft(Dvector &vect)
{
	int n = vect.size(); 
	if(n<=1)
	{
		return vect;
	}
	else
	{
		// On choisit les éléments d'indice pairs et impairs
		Dvector even_vect = vect.get_even();
		Dvector odd_vect = vect.get_odd();
		//Appel récursif sur chacun des sous-tableaux
		fft(even_vect);
		fft(odd_vect);
		for(int k =0; k <= n/2 - 1; k++){
		//	t = odd[k]exp (−2∗π∗i∗k/n)
		//	x[k] = even[k] + t
		//	x[k+n/2] = even[k] - t
			
		}
	
	}
}

