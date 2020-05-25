#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "./../headers/WaveModel.h"

using namespace std;

// === Classe abstraite ===

// === Méthodes de base ===

WaveModel::WaveModel()
{
    // windDirection = Dvector();
    intensity = 0;
    averageMatching = 0;
    averageWaveLength = 0;
    ajustWaveHeight = 0;
}

WaveModel::WaveModel(WaveModel &&model)
{
    windDirection = model.windDirection;

    averageMatching = model.averageMatching;
    intensity = model.intensity;
    averageWaveLength = model.averageWaveLength;
    ajustWaveHeight = model.ajustWaveHeight;
}

WaveModel::WaveModel(WaveModel const &model)
{
    windDirection = Dvector(model.windDirection);

    averageMatching = model.averageMatching;
    intensity = model.intensity;
    averageWaveLength = model.averageWaveLength;
    ajustWaveHeight = model.ajustWaveHeight;
}


// === Getters ===

Dvector WaveModel::getWindDir() {
    return windDirection;
}

double WaveModel::getAverageMatching() {
    return averageMatching;
}

double WaveModel::getIntensity() {
    return intensity;
}

double WaveModel::getAverageWaveLength() {
    return averageWaveLength;
}

double WaveModel::getAjustWaveHeight() {
    return ajustWaveHeight;
}

