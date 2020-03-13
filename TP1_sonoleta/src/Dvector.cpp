#include "Dvector.h"
#include <fstream>

Dvector::Dvector()
{
    v = new double[0]; // v vecteur de taille définie
    v_size = 0;
};

Dvector::Dvector(int size, int value)
{
    v = new double[size]; // v vecteur de taille définie
    v_size = size;
    for (int i = 0; i < size; i++)
        v[i] = value;
};

Dvector::Dvector(Dvector const& vect)
{
    v = new double[vect.v_size];
    v_size = vect.v_size;
    for (int i = 0; i < vect.v_size; i++)
        v[i] = *(vect.v + i);
};

Dvector::Dvector(std::string fichier)
{

    // Lit le fichier dans string
    std::ifstream flux(fichier);
    int vect_size = 0;
    if(flux)
    {
        std::string ligne; //Une variable pour stocker les lignes lues
        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            double n;
            try {
                n = std::stod(ligne);
                vect_size++;
            }
            catch(...) {
                // TODO : éviter les "..." => trouver la bonne erreur
            }
        }
    }
    else
    {
        v = new double[0];
        v_size = 0;
        return;
    }
    v = new double[vect_size];
    v_size = vect_size;

    flux.clear();
    flux.seekg(0, flux.beg);
    
    int i = 0;
    if(flux)
    {
        std::string ligne; //Une variable pour stocker les lignes lues
        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            double n;
            try {
                n = std::stod(ligne);
                v[i] = n;
                i++;
            }
            catch(...) {
                // TODO : éviter les "..." => trouver la bonne erreur
            }
        }
    }
}

Dvector::~Dvector()
{
    delete[] v;
};

void Dvector::display(std::ostream& str)
{
    for (long unsigned int i = 0; i< v_size; i++) {
        str << v[i] << std::endl;
    }
};

int Dvector::size()
{
    return v_size;
};

void Dvector::fillRandomly()
{
    for(long unsigned int i = 0; i<v_size; i++) {
        // fill with random
        v[i] = (double) rand() / RAND_MAX;
    }
};
