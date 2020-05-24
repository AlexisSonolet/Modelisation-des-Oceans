#pragma once

#include "GerstnerWave.h"
#include "WaveModel.h"

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

class GerstnerWaveModel:
    public WaveModel
    {
        public:
            // Méthodes de base
            GerstnerWaveModel();
            ~GerstnerWaveModel();
            GerstnerWaveModel(int n);
            GerstnerWaveModel(GerstnerWaveModel &&model);
            GerstnerWaveModel(GerstnerWaveModel const &model);
            GerstnerWaveModel& operator=(GerstnerWaveModel &&model);
            GerstnerWaveModel& operator=(GerstnerWaveModel const &model);
            // Utilitaires
            double operator()(Dvector x, int t);
            void setWave(GerstnerWave wave, int index);
            void setWave(int index, double A, double phi, Dvector* dir, double freq);
        
        private:
            GerstnerWave* listGerstnerWaves;
            int size;
};