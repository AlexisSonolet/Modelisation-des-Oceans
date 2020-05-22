#pragma once

#include <complex.h>
#include "Dvector.h"
#include "WaveModel.h"

#include "GerstnerWave.h"
#include "ComplexVector.h"
#include "FastFourier.h"

using namespace std;
class PhilipsWave
{
    public:
    // Méthodes principales
        PhilipsWave();
        ~PhilipsWave();
        PhilipsWave(double N, double M, double Lx, double Ly, 
                    double A, double w, double V, Dvector* dir);
        PhilipsWave(PhilipsWave &&model);
        PhilipsWave(PhilipsWave const &model);
        PhilipsWave operator=(PhilipsWave &&model);
        PhilipsWave operator=(PhilipsWave const &model);

        // Méthodes utiles
        double generate_xi();
        ComplexVector<complex<double>> operator()(int t);
        ComplexVector<complex<double>> get_height(int t); 

        // Getters & Setters
		
		// For debug
		void show_attributes();
    private:
        double L;
        double V;
        double w;
        double A;
        Dvector* dir;
        double Lx, Ly;
        double xi_r, xi_i;
		double N, M;
};

// ==== Autres fonctions utiles ====
