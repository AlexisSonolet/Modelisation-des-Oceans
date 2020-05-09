#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include "./../headers/PhilipsWave.h"

using namespace std;

// === Méthodes principales ===

PhilipsWave::PhilipsWave()
{
    L = 0;
    V = 0;
    w = 0;
    A = 0;
    Lx, Ly = 1, 1;
    xi_r, xi_i = 0, 0;
    dir = new Dvector(2, 1);
}

PhilipsWave::~PhilipsWave()
{
    delete k;
}

PhilipsWave::PhilipsWave(double n, double m, double Lx, double Ly, 
                         double A, double w, double V, Dvector* dir)
{
    Lx, Ly = Lx, Ly;
    n, m = n, m;
    V = V;
    A = A;
    w = w;
    double kx, ky;
    kx = 2 * M_PI * n / Lx;
    kx = 2 * M_PI * m / Ly;
    dir = dir;
    xi_r, xi_i = generate_xi(), generate_xi();

    
}

// === Méthodes utiles ===

double PhilipsWave::generate_xi()
{
    // TODO
    return 1;
}

double PhilipsWave::get_height(Dvector k, int t)
{
    double mod_k = sqrt(k*k);
    double Ph_k = (A * exp(-1/(pow(mod_k*L, 2))) / pow(mod_k, 2)) * pow(k*(*dir), 2);
    double height = sqrt(Ph_k/2);
    // height *= ((xi_r - ))
    return height;
}

double PhilipsWave::operator()(Dvector k, int t)
{
    return PhilipsWave::get_height(k, t);
}