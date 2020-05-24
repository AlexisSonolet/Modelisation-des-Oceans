#pragma once

#include <complex>
#include "ComplexVector.h"

/*!
* \brief Calcul FFT/IFFT
* \param vect : le vecteur sur lequel appliquer la FFT/IFFT
* \param inverse : FFT si false, IFFT si true
* Fait le calcul de la FFT en place
*/
void fft(ComplexVector<complex<double>> &vect, bool inverse = false);
