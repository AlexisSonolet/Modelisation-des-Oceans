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
        virtual WaveModel& operator=(WaveModel &&model) = 0;
        virtual WaveModel& operator=(WaveModel const &model) = 0;

        // Getters
        virtual Dvector* getWindDir();
        virtual double getAverageMatching();
        virtual double getIntensity();
        virtual double getAverageWaveLength();
        virtual double getAjustWaveHeight();

        // Get height
        virtual Dvector operator()(double t) = 0;
    
    private:
        Dvector* windDirection; /*< direction du vent */
        double averageMatching; /*< Alignement moyen des vagues avec le vent */
        double intensity; /*<Intensité*/
        double averageWaveLength; /*<Paramètre de longueur d'onde moyenne*/
        double ajustWaveHeight; /*<Paramètre d'ajustement des vagues*/
};
