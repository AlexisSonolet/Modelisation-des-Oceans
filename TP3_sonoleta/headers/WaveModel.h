#pragma once

#include "Dvector.h"

class WaveModel
{
    public:
        // Méthodes de base
        WaveModel();
        virtual ~WaveModel() = 0;
        WaveModel(WaveModel &&model);
        WaveModel(WaveModel const &model);
        // WaveModel operator=(WaveModel &&model);
        // WaveModel operator=(WaveModel const &model);
        
        // Getters
        virtual Dvector* getWindDir();
        virtual double getAverageMatching();
        virtual double getIntensity();
        virtual double getAverageWaveLength();
        virtual double getAjustWaveHeight();
    private:
        Dvector* windDirection;
        // Alignement moyen des vagues avec le vent
        double averageMatching;
        // Intensité (?!)
        double intensity;
        // Paramètre de longueur d'onde moyenne
        double averageWaveLength;
        // Paramètre d'ajustement des vagues
        double ajustWaveHeight;
};