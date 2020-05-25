#pragma once

#include <iostream>
#include "WaveModel.h"

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

/*!
 * \file Ocean.h
 * classe de simulation de l'ocean à partir d'un espace et d'un modèle
 *
 */

class Ocean
{
    public:
        // Méthodes de base
        Ocean();
        /*!
        * \brief Constructeur
        *  \param Lx, Ly : taille du domaine
        * \param nx, ny : nombre de points de discrétisation
        * \param Model : le modèle utilisé pour la modélisation
        */

        Ocean(double Lx, double Ly, int nx, int ny, WaveModel* Model);
        ~Ocean();

        // Setters
        void set_t(double t); /*<Setter du temps t*/
        void set_params(double Lx, double Ly, int nx, int ny);
        void set_model(WaveModel* Model);

        // Méthodes spécifiques
        /*!
        * \brief Génération hauteur
        * \ param value : la valeur initiale de la hauteur
        * Genere un océan avec la même hauteur value partout dans l'espace
        */
        void generateHeight(double value);

		/*!
        * \brief Calcul hauteur
        * \ param t : le temps
        * Calcule le champ des hauteurs à un instant t
        */
        void compute(double dt);
		/*!
        * \brief Génération OpenGL
        */
        float* getVertices();
        void plot(std::string path);

    private:
        double Lx; /*<longueur du domaine dans la direction x*/

        double Ly; /*< longueur du domaine dans la direction y*/
        int nx; /*<nombre de points de discrétisation selon x*/

        int ny;  /*<nombre de points de discrétisation selon y*/
        double t;  /*<le temps courant*/
        Dvector* H; /*< vecteur contenant la hauteur de la houle*/
        // double*** vertices;
        WaveModel* Model; /*<modèle utilisé*/
};
