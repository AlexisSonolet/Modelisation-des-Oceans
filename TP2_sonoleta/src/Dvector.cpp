#include "Dvector.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>

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
    std::ifstream flux(fichier);
    double n; // cast en double de la ligne courante
    int vect_size = 0;
    if(flux)
    {
        std::string ligne;
        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            try {
                n = std::stod(ligne);
                vect_size++;
            }
            catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */ }
        }
    }
    else
    {
        v = new double[0];
        v_size = 0;
        return;
    }
    flux.clear(); flux.seekg(0, flux.beg); // Réinitialiser la lecture du flux
    
    v = new double[vect_size];
    v_size = vect_size;
    // On remplit le vecteur
    int i = 0;
    std::string ligne;
    while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {
        try {
            n = std::stod(ligne);
            v[i] = n;
            i++;
        }
        catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */ }
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

double Dvector::get(int index)
{
    if (index >= v_size) {
        throw std::string("Error : cannot access to an index above the size of the vector");
        return 0;
    } else {
        return v[index];
    }
}

void Dvector::set(int index, double value)
{
    if (index >= v_size) {
        throw std::string("Error : cannot access to an index above the size of the vector");
    }

    v[index] = value;
}

Dvector Dvector::operator=(const Dvector &vect)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] v;
    v_size = vect.v_size;
    v = new double[v_size];
    memcpy(v, vect.v, v_size * sizeof(double));

    return *this;
}

Dvector Dvector::operator+=(Dvector &vect)
{
    if (v_size != vect.v_size) {
        throw std::string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] += vect.get(index);
    }
    return *this;
}

Dvector Dvector::operator-=(Dvector &vect)
{
    if (v_size != vect.v_size) {
        throw std::string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] -= vect.get(index);
    }
    return *this;
}

Dvector Dvector::operator*=(int i)
{
    for (int index = 0; index<v_size; index++) {
        v[index] *= i;
    }
    return *this;
}

Dvector Dvector::operator/=(int i)
{
    if (i == 0) {
        throw std::string("NullDivisionError : cannot divide by 0");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] /= i;
    }
    return *this;
}

Dvector Dvector::operator+(int i)
{
    Dvector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] + (double) i);
    }
    return vect;
}

Dvector Dvector::operator-(int i)
{
    Dvector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] - (double) i);
    }
    return vect;
}

Dvector Dvector::operator*(int i)
{
    Dvector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] * i);
    }
    return vect;
}

Dvector Dvector::operator/(int i)
{
    if (i == 0) {
        throw std::string("NullDivisionError : cannot divide by 0");
    }

    Dvector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] / i);
    }
    return vect;
}

Dvector Dvector::operator+(Dvector &vect)
{
    if (vect.v_size != v_size) {
        throw std::string("Error : size doesn't match");
    }
    Dvector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, v[index] + vect.get(index));
    }
    return vector;
}

Dvector Dvector::operator-(Dvector &vect)
{
    if (vect.v_size != v_size) {
        throw std::string("Error : size doesn't match");
    }
    Dvector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, v[index] - vect.get(index));
    }
    return vector;
}

Dvector Dvector::operator-()
{
    Dvector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, -v[index]);
    }
    return vector;
}