#pragma once

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

class WaveModel
{
    public:
        // Méthodes de base
        WaveModel();
        virtual ~WaveModel() = 0;
        WaveModel(WaveModel &&model);
        WaveModel(WaveModel const &model);
        // virtual WaveModel& operator=(WaveModel &&model);
        // virtual WaveModel& operator=(WaveModel const &model);
        
        // Getters
        virtual Dvector getWindDir();
        virtual double getAverageMatching();
        virtual double getIntensity();
        virtual double getAverageWaveLength();
        virtual double getAjustWaveHeight();

        // Get height
        virtual Dvector get_waves_height(double t) = 0;
    
    private:
        Dvector windDirection;
        // Alignement moyen des vagues avec le vent
        double averageMatching;
        // Intensité (?!)
        double intensity;
        // Paramètre de longueur d'onde moyenne
        double averageWaveLength;
        // Paramètre d'ajustement des vagues
        double ajustWaveHeight;
};