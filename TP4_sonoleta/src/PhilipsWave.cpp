#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include "./../headers/PhilipsWave.h"

using namespace std;

/**
 * calcule w(k)
 * 
 * k : norme du vecteur d'ondes
 * 
 * type :
 * - 0 : cas de houle
 * - 1 : eau peu profonde
 * - 2 : avec la tension de surface
 * 
 * D : profondeur
 * V : vitesse maximale du vent
 */
double compute_w(double k, int type, double D, double V)
{
    // Constantes
    double g = 9.81;
    double L = V*V/g;

    switch (type)
    {
    case 1:
        return g * k * tanh(k * D);
    case 2:
        return g * k * (1 + k*k*L*L);
    default:
        // Type = 0 ou autre
        return g * k;
    } 
}

double PhilipsWave::get_height()
{
    // TODO
}