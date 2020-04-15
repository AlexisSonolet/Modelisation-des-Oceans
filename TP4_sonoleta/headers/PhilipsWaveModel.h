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
            WaveModel& operator=(PhilipsWaveModel &&model);
            WaveModel& operator=(PhilipsWaveModel const &model);

            // Méthodes utiles
            double compute_h(Dvector x, double t);
        
        private:
            PhilipsWave* listPhilipsWaves;
            int size;
};
