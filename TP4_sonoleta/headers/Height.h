#pragma once

/*!
 * \file Height.h
 * Classe contenant l'ensemble des hauteurs dans un espace discrétisé
 *
 */


class Height
{
    public:
        // Basic methods
        Height();
        ~Height();
        /*!
        * \brief Constructeur
        * \param n_x : nombre de points de discrétisation selon x
        * \param n_y : nombre de points de discrétisation selon y
        * \param L_x : taille du domaine selon x
        * \param L_y : taille du domaine selon y
        */
        Height(int n_x, int n_y, double L_x, double L_y);
        Height(Height &&hauteurs);
        Height(Height const &hauteurs);
        Height operator=(Height &&hauteurs);
        Height operator=(Height const &hauteurs);
        double operator()(int x, int y);
        // Setters and getters
        void setLx(double value);
        double getLx();
        void setLy(double value);
        double getLy();
        void setNx(int value);
        double getNx();
        void setNy(int value);
        double getNy();
        void setValue(int x, int y, double value);
        // Other methods
        void plot(std::string path);

    private:
        double Lx, Ly;/*< taille de l'espace */
        int nx, ny;/*<Nombre de points de discrétisation*/
        double** heights;/*< La liste des hauteurs*/
};
