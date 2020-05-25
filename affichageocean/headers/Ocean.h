#pragma once

#include <iostream>
#include "WaveModel.h"

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

class Ocean
{
    public:
        // Méthodes de base
        Ocean();
        Ocean(double Lx, double Ly, int nx, int ny, WaveModel* Model);
        ~Ocean();

        // Setters
        void set_t(double t);
        void set_model(WaveModel* Model);

        // Getters
        uint32_t getNx();
		uint32_t getNy();

        // Méthodes spécifiques
        void generateHeight(double value);
        void compute(double dt);
        float* getVertices();
        void plot(std::string path);

    private:
        double Lx; // longueur du domaine dans la direction x
        double Ly; // longueur du domaine dans la direction y
        int nx; // nombre de points de discrétisation selon x
        int ny; // nombre de points de discrétisation selon y
        double t; // le temps courant
        Dvector H; // vecteur contenant la hauteur de la houle
        float* vert;
        WaveModel* Model; // modèle utilisé
};
