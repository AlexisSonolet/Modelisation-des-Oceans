#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "./../headers/GerstnerWaveModel.h"

using namespace std;


GerstnerWaveModel::GerstnerWaveModel()
{
    listGerstnerWaves = new GerstnerWave[0];
}

GerstnerWaveModel::~GerstnerWaveModel() 
{
    delete[] listGerstnerWaves;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel &&model)
{
    listGerstnerWaves = model.listGerstnerWaves;
    model.listGerstnerWaves = nullptr;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel const &model)
{
    int size = sizeof(model.listGerstnerWaves) / sizeof(GerstnerWave);
    listGerstnerWaves = new GerstnerWave[size];
    for (int i = 0; i < size; i++) {
        listGerstnerWaves[i] = GerstnerWave(model.listGerstnerWaves[i]);
    }
}

WaveModel& GerstnerWaveModel::operator=(GerstnerWaveModel &&model)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] listGerstnerWaves;
    listGerstnerWaves = model.listGerstnerWaves;
    model.listGerstnerWaves = nullptr;

    return *this;
}

WaveModel& GerstnerWaveModel::operator=(GerstnerWaveModel const &model)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] listGerstnerWaves;
    int size = sizeof(model.listGerstnerWaves) / sizeof(GerstnerWave);
    listGerstnerWaves = new GerstnerWave[size];
    for (int i = 0; i < size; i++) {
        listGerstnerWaves[i] = GerstnerWave(model.listGerstnerWaves[i]);
    }

    return *this;
}