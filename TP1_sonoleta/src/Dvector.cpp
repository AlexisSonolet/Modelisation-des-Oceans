#include "Dvector.h"

Dvector::Dvector()
{
    v = new double[0]; // v vecteur de taille définie
};

Dvector::Dvector(int size, int value)
{
    v = new double[size]; // v vecteur de taille définie
    for (int i = 0; i < size; i++)
        v[i] = value;
};

Dvector::~Dvector()
{
    delete[] v;
};

void Dvector::display(std::ostream& str)
{
    for (long unsigned int i = 0; i< sizeof(Dvector)/ sizeof(double); i++) {
        str << v[i];
        str << "/n";
    }
};