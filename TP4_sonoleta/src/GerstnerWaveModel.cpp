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

GerstnerWaveModel::~GerstnerWaveModel() 
{
    for (int i = 0; i < size; i++) {
        delete &listGerstnerWaves[i];
    }
    delete[] listGerstnerWaves;
}

GerstnerWaveModel::GerstnerWaveModel(int n)
{
    listGerstnerWaves = new GerstnerWave[n];
    size = n;
}

GerstnerWaveModel::GerstnerWaveModel(GerstnerWaveModel &&model)
{
    size = model.size;
    listGerstnerWaves = model.listGerstnerWaves;
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
    size = model.size;
    listGerstnerWaves = model.listGerstnerWaves;
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

double GerstnerWaveModel::operator()(Dvector x, int t)
{
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += listGerstnerWaves[i](x, t);
    }
}

void GerstnerWaveModel::setWave(GerstnerWave wave, int index)
{
    if (index >= size) {
        throw std::string("Error : index above list size");
        return;
    }
    listGerstnerWaves[index] = wave;

}

void GerstnerWaveModel::setWave(int index, double A, double phi, Dvector* dir, double freq)
{
    if (index >= size) {
        throw std::string("Error : index above list size");
        return;
    }
    GerstnerWave wave = GerstnerWave(A, phi, dir, freq);
    listGerstnerWaves[index] = wave;
}