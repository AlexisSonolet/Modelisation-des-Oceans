#pragma once

#include "Dvector.h"
#include "WaveModel.h"

class PhilipsWave
{
    public:
        double get_height();
    
    private:
        // TODO
};

// ==== Autres fonctions utiles ====

double compute_w(double k, int type=0, double D = 1, double V = 1);