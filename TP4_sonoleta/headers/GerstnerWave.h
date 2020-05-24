#pragma once

#include "ComplexVector.h"
using Dvector = ComplexVector<double>;

/*!
 * \file GerstnerWave.h
 * classe des vague de Gerstner avec les méthodes associées
 *
 *
 */

class GerstnerWave
{
    public:
        // Méthodes de base
        /*!
		 * \brief Constructeur par défaut
		 */
        GerstnerWave();
        /*!
        * \brief Destructeur
        * Destructeur de la classe Dvector
        */
        ~GerstnerWave();
        /*!
         * Constructeur
         * \param A : amplitude de l'onde
         * \param Phi : phase de l'onde
         * \param *dir : direction du vecteur d'onde
         * \param freq : frequence de l'onde
         */
        GerstnerWave(double A, double Phi, Dvector* dir, double freq);
        // Constructeurs par recopie
        GerstnerWave(GerstnerWave &&model);/*< Constructeur par recopie*/
        GerstnerWave(GerstnerWave const &model);/*< Constructeur par recopie*/
        GerstnerWave operator=(GerstnerWave &&model);/*< Opérateur d'affectation par recopie*/
        GerstnerWave operator=(GerstnerWave const &model);
        double operator()(Dvector x, int t);

        // Setters & Getters
        double getAmplitude();
        void setAmplitude(double value);
        double getPhase();
        void setPhase(double value);
        Dvector* getDirection();
        void setDirection(Dvector* value);
        double getFrequency();
        void setFrequency(double value);
    private:
        double amplitude;/*<amplitude de l'onde*/
        double phase;/*< phase de l'onde*/
        Dvector* direction;/*< direction du vecteur d'onde */
        double frequency;/*< frequence de l'onde */
};

#define G 9.81 /*< definition de G la constante gravitationelle */
#define W_TYPE 0 /*< type (entre 0 et 2) utilisé pour le type 3 de compute_freq*/

/*!
* \brief Calcule le module du vecteur d'onde
*  \param dir : le vecteur d'onde
*/
double module(Dvector* dir);
/*!
* \brief Calcule la fréquence en fonction de la direction
*  \param dir : le vecteur d'onde
* \param type : le cas dans lequel on se trouve
* \ param D : distance du sol vis à vis du niveau moyen de l'océan
* \param T : période de répétition des vagues
*/
double compute_freq(Dvector* dir, int type = 0,
                    double D = 0, double L = 0, double T = 1);
