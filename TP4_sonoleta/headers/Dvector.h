#pragma once

#include <iostream>

/*!
 * \file Dvector.h
 * classe vecteur de base, peut stocker des nombres au format double
 */

class Dvector
{
    public:
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
				void display(std::ostream& str);
					 /*!
		* \brief Taille du vecteur
		*/
				int size() const;
				/*!
 		* Remplit le vecteur de manière aléatoire
 		*/
 			  void fillRandomly();
 			 /*!
 			 * \brief getter
 			 */
 			  double get(int index) const;
 			 /*!
 			 * \brief getter/setter
 			 * \param i : index
 			 */
 			  double & operator()(int i) const;
 			 /*!
 			 * \brief setter
 			 * \param index : index de l'élément à modifier
 			 * \param value : la valeur à insérer
 			 */
 			  void set(int index, double value);
 			 /*!
 			 * \brief changer la taille
 			 * \param size : la nouvelle taille
 			 */
        void set_size(int size);
				/*!
 			 * \brief changer tout les éléments du vecteurs
 			 * \param *vect : pointeur des nouveaux éléments
 			 */
 			  void set_v(double* vect);
 			 /*!
 			 * \brief getter de l'ensemble des éléments
 			 */
 			  double* get_v() const;

				/*!
				* \brief renvoie les composantes d'index pair
				*/
				Dvector get_even() const;
				/*!
				* \brief renvoie les composantes d'index impair
				*/
				Dvector get_odd() const;
				// Les opérateurs
        Dvector operator=(const Dvector &vect);
        Dvector operator+=(const Dvector &vect);
        Dvector operator-=(const Dvector &vect);
        Dvector operator*=(int i);
        Dvector operator*=(const Dvector &vect);
        Dvector operator/=(int i);
        Dvector operator+(int i);
        Dvector operator-(int i);
        Dvector operator*(int i);
        double operator*(const Dvector &vect);
        Dvector operator/(int i);
        Dvector operator+(Dvector &vect);
        Dvector operator-(Dvector &vect);
        Dvector operator-();
        bool operator==(const Dvector &vect);
				/*!
				* \brief Changer la taille et insérer de nouvelles valeurs en queue
				* \param size : la nouvelle taille du vecteur
				* \param vect : le vecteur de valeurs à insérer en queue si la nouvelle taille est supérieure à l'ancienne
				*/
        void resize(int size, double* vect = 0);
				/*!
				* \brief Verification de nullitude
				*/
        bool isnull();

    private:
        double* v; /*< Liste des éléments du vecteur */
        int v_size; /*< Taille du vecteur */
};

std::ostream& operator<<(std::ostream& out, const Dvector& v);
std::istream& operator>>(std::istream& in, Dvector& v);

// === Math constants ===
#define g 9.81
#define M_PI 3.14159265358979323846264338327950288
