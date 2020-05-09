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
    n , m = 1, 1;
    xi_r, xi_i = 0, 0;
    k = new Dvector(2, 1);
}

PhilipsWave::~PhilipsWave()
{
    delete k;
}

PhilipsWave::PhilipsWave(double n, double m, double Lx, double Ly, 
                         double A, double w, double V)
{
    Lx, Ly = Lx, Ly;
    n, m = n, m;
    V = V;
    A = A;
    w = w;
    double kx, ky;
    kx = 2 * M_PI * n / Lx;
    kx = 2 * M_PI * m / Ly;
    k = new Dvector(2, 1);
    k->set(0, kx);
    k->set(1, ky);
    xi_r, xi_i = generate_xi(), generate_xi();
}

// === Méthodes utiles ===

double PhilipsWave::generate_xi()
{
    // TODO
    return 1;
}

double PhilipsWave::get_height(PARAMS, int t)
{
    // TODO
    return 1;
}

double PhilipsWave::operator()(PARAMS, int t)
{
    return PhilipsWave::get_height(PARAMS, t);
}