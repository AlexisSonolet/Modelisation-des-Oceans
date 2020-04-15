#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "./../headers/Height.h"

using namespace std;


// === Basic methods ===

Height::Height()
{
    Lx = 0;
    Ly = 0;
    nx = 0;
    ny = 0;
    heights = new double*[0];
}

Height::~Height()
{
    for (int x = 0; x < nx; x++) {
        delete[] heights[x];
    }
    delete[] heights;
}

Height::Height(int n_x, int n_y, double L_x, double L_y)
{
    Lx = L_x;
    Ly = L_y;
    nx = n_x;
    ny = n_y;
    heights = new double*[nx];
    for (int x = 0; x < nx; x++) {
        heights[x] = new double[ny];
        for (int y = 0; y < ny; y++) {
            heights[x][y] = 0;
        }
    }
}

Height::Height(Height &&hauteurs)
{
    Lx = hauteurs.Lx;
    Ly = hauteurs.Ly;
    nx = hauteurs.nx;
    ny = hauteurs.ny;
    heights = hauteurs.heights;
    hauteurs.heights = nullptr;
}

Height::Height(Height const &hauteurs)
{
    Lx = hauteurs.Lx;
    Ly = hauteurs.Ly;
    nx = hauteurs.nx;
    ny = hauteurs.ny;
    heights = new double*[nx];
    for (int x = 0; x < nx; x++) {
        heights[x] = new double[ny];
        for (int y = 0; y < ny; y++) {
            heights[x][y] = hauteurs.heights[x][y];
        }
    }
}

Height Height::operator=(Height &&hauteurs)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] heights;
    Lx = hauteurs.Lx;
    Ly = hauteurs.Ly;
    nx = hauteurs.nx;
    ny = hauteurs.ny;
    heights = hauteurs.heights;
    hauteurs.heights = nullptr;

    return *this;
}

Height Height::operator=(Height const &hauteurs)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] heights;
    Lx = hauteurs.Lx;
    Ly = hauteurs.Ly;
    nx = hauteurs.nx;
    ny = hauteurs.ny;
    heights = new double*[nx];
    for (int x = 0; x < nx; x++) {
        heights[x] = new double[ny];
        memcpy(heights[x], hauteurs.heights[x], 
                ny * sizeof(double));
    }

    return *this;
}

double Height::operator()(int x, int y)
{
    if (nx <= x) {
        cout << "Element hors du domaine !" << endl;
        exit(EXIT_FAILURE);
    }
    if (ny <= y) {
        cout << "Element hors du domaine !" << endl;
        exit(EXIT_FAILURE);
    }
    return heights[x][y];
}


// === Setters and getters ===

void Height::setLx(double value) {
    Lx = value;
}

double Height::getLx() {
    return Lx;
}

void Height::setLy(double value) {
    Ly = value;
}

double Height::getLy() {
    return Ly;
}

void Height::setNx(int value) {
    nx = value;
}

double Height::getNx() {
    return nx;
}

void Height::setNy(int value) {
    ny = value;
}

double Height::getNy() {
    return ny;
}

void Height::setValue(int x, int y, double value) {
    if (nx <= x) {
        cout << "Element hors du domaine !" << endl;
        exit(EXIT_FAILURE);
    }
    if (ny <= y) {
        cout << "Element hors du domaine !" << endl;
        exit(EXIT_FAILURE);
    }
    heights[x][y] = value;
}


// === Other methods ===

void Height::plot(string path)
{
    ofstream file;
    file.open(path + "plotting.dat");
    for (int x = 0; x < nx; x++) {
        file << "# Ligne n°" + to_string(x) + "\n";
        for (int y = 0; y < ny; y++) {
            file << to_string(x) + " " + to_string(y) + " " + to_string(heights[x][y]) + "\n";
        }
        file << "\n"; // Ligne blanche pour séparer les lignes
    }
    file.close();
}
