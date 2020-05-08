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
    size = 0;
}

GerstnerWaveModel::GerstnerWaveModel(int n)
{
    listGerstnerWaves = new GerstnerWave[n];
    size = n;
}

GerstnerWaveModel::~GerstnerWaveModel() 
{
    delete[] listGerstnerWaves;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel &&model)
{
    listGerstnerWaves = model.listGerstnerWaves;
    size = model.size;
    model.listGerstnerWaves = nullptr;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel const &model)
{
    size = model.size;
    listGerstnerWaves = new GerstnerWave[size];
    for (int i = 0; i < size; i++) {
        listGerstnerWaves[i] = GerstnerWave(model.listGerstnerWaves[i]);
    }
}

GerstnerWaveModel& GerstnerWaveModel::operator=(GerstnerWaveModel &&model)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] listGerstnerWaves;
    listGerstnerWaves = model.listGerstnerWaves;
    size = model.size;
    model.listGerstnerWaves = nullptr;

    return *this;
}

GerstnerWaveModel& GerstnerWaveModel::operator=(GerstnerWaveModel const &model)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] listGerstnerWaves;
    size = model.size;
    listGerstnerWaves = new GerstnerWave[size];
    for (int i = 0; i < size; i++) {
        listGerstnerWaves[i] = GerstnerWave(model.listGerstnerWaves[i]);
    }

    return *this;
}

void GerstnerWaveModel::setGerstnerWave(int i, GerstnerWave wave)
{
    if (i >= size) {
        cout << "Indice supérieur à la taille du vecteur !" << endl;
        exit(EXIT_FAILURE);
    }
    listGerstnerWaves[i] = wave;
}