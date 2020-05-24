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
    wave = new PhilipsWave;
}

PhilipsWaveModel::PhilipsWaveModel(double N, double M, double Lx, double Ly, 
                                   double A, double w, double V, Dvector* dir)
{
    wave = new PhilipsWave(N, M, Lx, Ly, A, w, V, dir);
}

PhilipsWaveModel::~PhilipsWaveModel()
{
    delete wave;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel &&model)
{
    wave = model.wave;
    model.wave = nullptr;
}

PhilipsWaveModel::PhilipsWaveModel(PhilipsWaveModel const &model)
{
    wave = model.wave;
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel &&model)
{
    delete wave;
    wave = model.wave;
    model.wave = nullptr;

    return *this;
}

PhilipsWaveModel& PhilipsWaveModel::operator=(PhilipsWaveModel const &model)
{
    delete wave;
    wave = model.wave;

    return *this;
}


// === Méthodes utiles ===

ComplexVector<complex<double>> PhilipsWaveModel::compute_h(double t)
{
    ComplexVector<complex<double>> h = 0;
    h = wave->get_height(t);
    return h;
}


// === Compute height ===

Dvector PhilipsWaveModel::operator()(double t)
{
    return wave->compute_h(t);
}
