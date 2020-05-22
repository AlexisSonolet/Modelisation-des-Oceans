#pragma once

#include "Dvector.h"
#include "WaveModel.h"
#include "PhilipsWave.h"

class PhilipsWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            PhilipsWaveModel();
            ~PhilipsWaveModel();
            PhilipsWaveModel(PhilipsWaveModel &&model);
            PhilipsWaveModel(PhilipsWaveModel const &model);
            PhilipsWaveModel& operator=(PhilipsWaveModel &&model);
            PhilipsWaveModel& operator=(PhilipsWaveModel const &model);

            // Méthodes utiles
            ComplexVector<complex<double>> compute_h(double t);
			ComplexVector<complex<double>> operator()(double t);
        
        private:
            PhilipsWave* listPhilipsWaves;
            int size;
};
