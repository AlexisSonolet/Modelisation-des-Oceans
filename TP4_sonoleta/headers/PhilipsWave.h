#pragma once

#include "Dvector.h"
#include "WaveModel.h"

class PhilipsWave
{
    public:
    // Méthodes principales
        PhilipsWave();
        ~PhilipsWave();
        PhilipsWave(double n, double m, double Lx, double Ly, 
                    double A, double w, double V, Dvector* dir);
        PhilipsWave(PhilipsWave &&model);
        PhilipsWave(PhilipsWave const &model);
        PhilipsWave operator=(PhilipsWave &&model);
        PhilipsWave operator=(PhilipsWave const &model);

        // Méthodes utiles
        double generate_xi();
        double operator()(Dvector k, int t);
        double get_height(Dvector k, int t);

        // Getters & Setters
    
    private:
        double L;
        double V;
        double w;
        double A;
        Dvector* dir;
        double Lx, Ly;
        double xi_r, xi_i;
};

// ==== Autres fonctions utiles ====