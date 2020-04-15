#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <tgmath.h>
#include "./../headers/PhilipsWaveModel.h"

using namespace std;

double PhilipsWaveModel::compute_h(Dvector x, double t)
{
    double h = 0;
    for (int i = 0; i < size; i++) {
        h += listPhilipsWaves[i].get_height();
    }
}