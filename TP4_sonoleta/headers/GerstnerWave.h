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

#define G 9.81
#define W_TYPE 0 // type (entre 0 et 2) utilisé pour le type 3 de compute_freq

double module(Dvector* dir);
double compute_freq(Dvector* dir, int type = 0, 
                    double D = 0, double L = 0, double T = 1);