#pragma once

#include <complex.h>
#include "Dvector.h"
#include "WaveModel.h"

#include "./../headers/GerstnerWave.h"
#include "./../headers/ComplexVector.h"


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
        double operator()(int t);
        ComplexVector<complex<double>> get_height(int t); // TODO : IFFT 

        // Getters & Setters
    
    private:
        double L;
        double V;
        double w;
        double A;
        Dvector* dir;
        double Lx, Ly;
        double xi_r, xi_i;
		int N, M;
};

// ==== Autres fonctions utiles ====
