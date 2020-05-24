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
            GerstnerWaveModel(int n, double Lx, double Ly, int nx, int ny);
            GerstnerWaveModel(GerstnerWaveModel &&model);
            GerstnerWaveModel(GerstnerWaveModel const &model);
            GerstnerWaveModel& operator=(GerstnerWaveModel &&model);
            GerstnerWaveModel& operator=(GerstnerWaveModel const &model);
            // Utilitaires
            Dvector operator()(double t);
            void setWave(GerstnerWave wave, int index);
            void setWave(int index, double A, double phi, Dvector* dir, double freq);
            void setParams(double Lx, double Ly, int nx, int ny);

        private:
            GerstnerWave* listGerstnerWaves;
            int size;
            double Lx, Ly;
            int nx, ny;
};