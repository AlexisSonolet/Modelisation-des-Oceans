#pragma once

#include "Dvector.h"
#include "GerstnerWave.h"
#include "WaveModel.h"

class GerstnerWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            GerstnerWaveModel();
            ~GerstnerWaveModel();
            GerstnerWaveModel(GerstnerWaveModel &&model);
            GerstnerWaveModel(GerstnerWaveModel const &model);
            WaveModel& operator=(GerstnerWaveModel &&model);
            WaveModel& operator=(GerstnerWaveModel const &model);
        
        private:
            GerstnerWave* listGerstnerWaves;
    };