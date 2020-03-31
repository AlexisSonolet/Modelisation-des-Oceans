#pragma once

#include "Dvector.h"

class GerstnerWave
{
    public:
        // Méthodes de base
        GerstnerWave();
        virtual ~GerstnerWave() = 0;
        GerstnerWave(GerstnerWave &&model);
        GerstnerWave(GerstnerWave const &model);
        // GerstnerWave operator=(GerstnerWave &&model);
        // GerstnerWave operator=(GerstnerWave const &model);
        double operator()(Dvector x0, int t);

        // Setters & Getters
        virtual double getAmplitude();
        virtual void setAmplitude(double value);
        virtual double getPhase();
        virtual void setPhase(double value);
        virtual Dvector* getDirection();
        virtual void setDirection(Dvector* value);
        virtual double getFrequency();
        virtual void setFrequency(double value);
    private:
        double amplitude;
        double phase;
        Dvector* direction;
        double frequency;
};