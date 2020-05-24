#pragma once

#include <iostream>

/*!
 * \file Dvector.h
 * classe vecteur de base, peut stocker des nombres au format double
 *
 *
 */

class Dvector
{
    public :
		/*!
		 * \brief Constructeur par défault
		 */
        Dvector();
		/*!
		 * Constructeur avec remplissage à valeur fixe
		 * \param size : taille du vecteur
		 * \param value : la valeur à mettre dans toutes les cases
		 *
		 */
        Dvector(int size, int value=0); 
        
		/*!
		 * \brief Constructeur par recopie
		 * \param vect : le vecteur à recopier
		 */
		Dvector(Dvector const& vect);
		/*!
		 * \brief Constructeur à partir d'un fichier
		 */
        Dvector(std::string fichier);
        /*!
		 * \brief Destructeur
		 * Destructeur de la classe Dvector
		 */
		~Dvector();
        /* 
		 * \brief Affichage
		 * \param str : flux dans lequel afficher l'objet Dvector
		 * Fonction d'affichage
		 */
		void display(std::ostream& str);
        /*!
		 * \brief Taille du vecteur
		 */
		int size();
		/*!
		 * Remplit le vecteur de manière aléatoire
		 */
        void fillRandomly();
    
    private:
        double* v; /*< Liste des éléments du vecteur */
        int v_size; /*< Taille du vecteur */
};
