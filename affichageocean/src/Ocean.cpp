#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include "./../headers/Ocean.h"

using namespace std;


// === Méthodes de base ===

Ocean::Ocean()
{
    Lx = 0;
    Ly = 0;
    nx = 0;
    ny = 0;
    t = 0;
    H = Dvector();
    Model = nullptr;
    vert = nullptr;
}

Ocean::Ocean(double Lx, double Ly, int nx, int ny, WaveModel* Model) :
    Lx{Lx},
    Ly{Ly},
    nx{nx},
    ny{ny},
    Model{Model},
    t{0},
    H{Dvector(nx*ny)},
    vert{new float[3*nx*ny]}
{
}

Ocean::~Ocean()
{
    delete Model;
}


// === Setters ===

void Ocean::set_t(double t)
{
    t = t;
}

void Ocean::set_model(WaveModel* WModel)
{
    delete Model;
    Model = WModel;
}


// === Getters ===
uint32_t Ocean::getNx()
{
    return (uint32_t) nx;
}

uint32_t Ocean::getNy()
{
    return (uint32_t) ny;
}


// === Méthodes spécifiques ===

void Ocean::generateHeight(double value)
{
    // Initialisation de la hauteur
    H = Dvector(nx*ny, value);
}

void Ocean::compute(double dt)
{
    t += dt;
    H = Model->get_waves_height(t);
}

float* Ocean::getVertices()
{
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            vert[3*(x*ny+y) + 0] = x*Lx/nx; // x
            vert[3*(x*ny+y) + 1] = y*Ly/ny; // y
            vert[3*(x*ny+y) + 2] = H.get(x*ny+y); // z
        }
    }
    return vert;
}

void Ocean::plot(std::string path)
{
    ofstream file;
    file.open(path + "plotting_ocean.dat");
    for (int x = 0; x < nx; x++) {
        file << "# Ligne n°" + to_string(x) + "\n";
        for (int y = 0; y < ny; y++) {
            file << to_string(x) +" "+ to_string(y) +" "+ to_string(H.get(x*ny+y)) +"\n";
        }
        file << "\n"; // Ligne blanche pour séparer les lignes
    }
    file.close();
}