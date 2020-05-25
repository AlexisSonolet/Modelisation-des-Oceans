#pragma once

#include "WaveModel.h"
#include "PhilipsWave.h"

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

class PhilipsWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            PhilipsWaveModel();
            PhilipsWaveModel(int N, int M, double Lx, double Ly, 
                             double A, double w, double V, Dvector dir);
            ~PhilipsWaveModel();
            PhilipsWaveModel(PhilipsWaveModel &&model);
            PhilipsWaveModel(PhilipsWaveModel const &model);
            PhilipsWaveModel& operator=(PhilipsWaveModel &&model);
            PhilipsWaveModel& operator=(PhilipsWaveModel const &model);

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
