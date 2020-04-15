#pragma once

#include "Dvector.h"

class GerstnerWave
{
    public:
        // Méthodes de base
        GerstnerWave();
        ~GerstnerWave();
        GerstnerWave(double A, double Phi, Dvector* dir, double freq);
        GerstnerWave(GerstnerWave &&model);
        GerstnerWave(GerstnerWave const &model);
        GerstnerWave operator=(GerstnerWave &&model);
        GerstnerWave operator=(GerstnerWave const &model);
        double operator()(Dvector x, int t);

        // Setters & Getters
        double getAmplitude();
        void setAmplitude(double value);
        double getPhase();
        void setPhase(double value);
        Dvector* getDirection();
        void setDirection(Dvector* value);
        double getFrequency();
        void setFrequency(double value);
    private:
        double amplitude;
        double phase;
        Dvector* direction;
        double frequency;
};