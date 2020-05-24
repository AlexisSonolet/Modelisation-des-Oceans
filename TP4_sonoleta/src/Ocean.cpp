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
    Lx, Ly = 0, 0;
    nx, ny = 0, 0;
    t = 0;
    H = new Dvector();
    Model = nullptr;
}

Ocean::Ocean(double Lx, double Ly, int nx, int ny, WaveModel* Model)
{
    Lx, Ly = Lx, Ly;
    nx, ny = nx, ny;
    Model = Model;
    t = 0;
    H = new Dvector(nx*ny);
}

Ocean::~Ocean()
{
    delete Model;
    delete H;
}


// === Setters ===

void Ocean::set_t(double t)
{
    t = t;
}

void Ocean::set_params(double Lx, double Ly, int nx, int ny)
{
    Lx, Ly = Lx, Ly;
    nx, ny = nx, ny;

    delete H;
    H = new Dvector(nx*ny);
}

void Ocean::set_model(WaveModel* Model)
{
    Model = Model;
}


// === Méthodes spécifiques ===

void Ocean::generateHeight(double value)
{
    // Initialisation de la hauteur
    delete H;
    H = new Dvector(nx*ny, value);
}

void Ocean::compute(double t)
{
    // TODO
    // Ajouter une fonction get_height sur WaveModel...
}

Dvector* Ocean::gl_vertices()
{
    // TODO
}

void Ocean::plot(std::string path)
{
    ofstream file;
    file.open(path + "plotting_ocean.dat");
    for (int x = 0; x < nx; x++) {
        file << "# Ligne n°" + to_string(x) + "\n";
        for (int y = 0; y < ny; y++) {
            file << to_string(x) +" "+ to_string(y) +" "+ to_string(H->get(x*nx+y)) +"\n";
        }
        file << "\n"; // Ligne blanche pour séparer les lignes
    }
    file.close();
}