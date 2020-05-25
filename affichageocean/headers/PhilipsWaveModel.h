#pragma once

#include <complex.h>

#include "WaveModel.h"
#include "FastFourier.h"
#include "ComplexVector.h"

using namespace std;
using Dvector = ComplexVector<double>;

class PhilipsWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            PhilipsWaveModel(int N, int M, double Lx, double Ly, 
                             double A, double w, double V, Dvector dir);

            // Méthodes utiles
            double generate_xi();
            ComplexVector<complex<double>> get_height(double t); 

            // Compute height
            Dvector get_waves_height(double t);

            // For debug
            void show_attributes();
        
        private:
            double L;
            double V;
            double w;
            double A;
            Dvector dir;
            double Lx, Ly;
            double xi_r, xi_i;
            int N, M;
};

// Autres fonctions
double module(Dvector dir);

#define W_TYPE 0 // type (entre 0 et 2) utilisé pour le type 3 de compute_freq
double compute_freq(Dvector dir, int type = 0, 
                    double D = 0, double L = 0, double T = 1);