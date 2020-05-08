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
            GerstnerWaveModel(int n);
            ~GerstnerWaveModel();
            GerstnerWaveModel(GerstnerWaveModel &&model);
            GerstnerWaveModel(GerstnerWaveModel const &model);
            GerstnerWaveModel& operator=(GerstnerWaveModel &&model);
            GerstnerWaveModel& operator=(GerstnerWaveModel const &model);
            void setGerstnerWave(int i, GerstnerWave wave);
        private:
            GerstnerWave* listGerstnerWaves;
            int size;
    };