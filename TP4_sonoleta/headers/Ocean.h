#pragma once

#include <iostream>

#include "Dvector.h"
#include "WaveModel.h"

class Ocean
{
    public:
        // Méthodes de base
        Ocean();
        ~Ocean();
        void generateHeight(double value);
        void compute(double t);
        Dvector* gl_vertices();
        void plot(std::string path);

    private:
        double Lx; // longueur du domaine dans la direction x
        double Ly; // longueur du domaine dans la direction y
        int nx; // nombre de points de discrétisation selon x
        int ny; // nombre de points de discrétisation selon y
        double t; // le temps courant
        Dvector* H; // vecteur contenant la hauteur de la houle
        WaveModel* Model; // modèle utilisé
};
