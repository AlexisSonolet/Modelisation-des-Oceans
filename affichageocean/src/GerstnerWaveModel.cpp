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
    Lx, Ly = 1, 1;
    nx, ny = 0, 0;
}

GerstnerWaveModel::~GerstnerWaveModel() 
{
    for (int i = 0; i < size; i++) {
        delete &listGerstnerWaves[i];
    }
    delete[] listGerstnerWaves;
}

GerstnerWaveModel::GerstnerWaveModel(int n, double Lx, double Ly, int nx, int ny)
{
    listGerstnerWaves = new GerstnerWave[n];
    size = n;
    Lx, Ly = Lx, Ly;
    nx, ny = nx, ny;
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

Dvector GerstnerWaveModel::operator()(double t)
{
    Dvector H = Dvector(nx*ny);
    Dvector point = Dvector(2);
    for (double x = 0; x < nx; x++) {
        for (double y = 0; y < ny; y++) {
            point.set(0, x*Lx/nx);
            point.set(1, y*Ly/ny);
            double sum = 0;
            for (int i = 0; i < size; i++) {
                sum += listGerstnerWaves[i](x, t);
            }
            H.set(x*ny + y, sum);
        }
    }
    return H;
}

void GerstnerWaveModel::setWave(GerstnerWave wave, int index)
{
    if (index >= size) {
        throw std::string("Error : index above list size");
        return;
    }
    listGerstnerWaves[index] = wave;

}

void GerstnerWaveModel::setParams(double Lx, double Ly, int nx, int ny)
{
    Lx, Ly = Lx, Ly;
    nx, ny = nx, ny;
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