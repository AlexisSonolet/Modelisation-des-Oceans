#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include "./../headers/PhilipsWaveModel.h"

using namespace std;


// === Méthodes de base ===

PhilipsWaveModel::PhilipsWaveModel()
{
    listPhilipsWaves = new PhilipsWave[0];
    size = 0;
}

PhilipsWaveModel::~PhilipsWaveModel()
{
    for (int i = 0; i < size; i++) {
        delete &listPhilipsWaves[i];
    }
    delete[] listPhilipsWaves;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel &&model)
{
    size = model.size;
    listPhilipsWaves = model.listPhilipsWaves;
    model.listPhilipsWaves = nullptr;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel const &model)
{
    size = model.size;
    listPhilipsWaves = new PhilipsWave[size];
    for (int i = 0; i < size; i++) {
        listPhilipsWaves[i] = PhilipsWave(model.listPhilipsWaves[i]);
    }
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel &&model)
{
    delete[] listPhilipsWaves;
    size = model.size;
    listPhilipsWaves = model.listPhilipsWaves;
    model.listPhilipsWaves = nullptr;

    return *this;
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel const &model)
{
    delete[] listPhilipsWaves;
    size = model.size;
    for (int i = 0; i< size; i++) {
        listPhilipsWaves[i] = PhilipsWave(model.listPhilipsWaves[i]);
    }

    return *this;
}


// === Méthodes utiles ===

ComplexVector<complex<double>> PhilipsWaveModel::compute_h(double t)
{
    ComplexVector<complex<double>> h = 0;
    for (int i = 0; i < size; i++) {
        h += listPhilipsWaves[i].get_height(t);
    }
    return h;
}

ComplexVector<complex<double>> PhilipsWaveModel::operator()(double t)
{
    return PhilipsWaveModel::compute_h(t);
}
