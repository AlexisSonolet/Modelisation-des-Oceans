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
            PhilipsWaveModel(double N, double M, double Lx, double Ly, 
                             double A, double w, double V, Dvector* dir);
            ~PhilipsWaveModel();
            PhilipsWaveModel(PhilipsWaveModel &&model);
            PhilipsWaveModel(PhilipsWaveModel const &model);
            PhilipsWaveModel& operator=(PhilipsWaveModel &&model);
            PhilipsWaveModel& operator=(PhilipsWaveModel const &model);

            // Méthodes utiles
            ComplexVector<complex<double>> compute_h(double t);

            // Compute height
			Dvector operator()(double t);
        
        private:
            PhilipsWave* wave;
};
