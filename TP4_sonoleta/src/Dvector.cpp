#include <fstream>
#include <ostream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "./../headers/Dvector.h"

using namespace std;

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

Dvector::Dvector(string fichier)
{
    ifstream flux(fichier);
    double n; // cast en double de la ligne courante
    int vect_size = 0;
    if(flux)
    {
        string ligne;
        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            try {
                n = stod(ligne);
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
    string ligne;
    while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {
        try {
            n = stod(ligne);
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

void Dvector::display(ostream& str)
{
    for (long unsigned int i = 0; i< v_size; i++) {
        str << v[i] << endl;
    }
};

int Dvector::size() const
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

double Dvector::get(int index) const
{
    if (index >= v_size) {
        throw string("Error : cannot access to an index above the size of the vector");
        return 0;
    } else {
        return v[index];
    }
}

void Dvector::set(int index, double value)
{
    if (index >= v_size) {
        throw string("Error : cannot access to an index above the size of the vector");
    }

    v[index] = value;
}

void Dvector::set_size(int size)
{
    v_size = size;
}

void Dvector::set_v(double* vect)
{
    v = vect;
}

double* Dvector::get_v() const
{
    return v;
}

Dvector Dvector::get_even() const
{
	Dvector even((int)((v_size-1)/2) + 1);
	for(int index = 0; index < v_size; index+=2)
	{
		even.set(index/2, v[index]);
	}
	return even;	
}

Dvector Dvector::get_odd() const
{
	Dvector odd((int)(v_size/2));
	for(int index = 1; index < v_size; index+=2)
	{
		odd.set((int)(index/2), v[index]);
	}
	return odd;	
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

Dvector Dvector::operator+=(const Dvector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] += vect.get(index);
    }
    return *this;
}

Dvector Dvector::operator-=(const Dvector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
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

Dvector Dvector::operator*=(const Dvector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] *= vect.v[index];
    }
    return *this;
}

Dvector Dvector::operator/=(int i)
{
    if (i == 0) {
        throw string("NullDivisionError : cannot divide by 0");
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

double Dvector::operator*(const Dvector &vector)
{
    // Produit scalaire
    if (v_size != vector.v_size) {
        throw string("Error : vectors of different sizes");
    }
    double value;
    for (int index = 0; index<v_size; index++) {
        value += index, v[index] * vector.v[index];
    }
    return value;
}

Dvector Dvector::operator/(int i)
{
    if (i == 0) {
        throw string("NullDivisionError : cannot divide by 0");
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
        throw string("Error : size doesn't match");
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
        throw string("Error : size doesn't match");
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

ostream& operator<<(ostream& out, const Dvector& v)
{
    for (long unsigned int i = 0; i<v.size() ; i++) {
        out << v.get(i) << endl;
    }
    return out;
}

istream& operator>>(istream& in, Dvector& v)
{
    int index = 0; // taille de vect

    string input;
    double n;
    while (getline(cin, input) && !input.empty()) {
        try {
            stringstream ss(input);
            ss >> n;
            v.set(index, n);
            index++;
        }
        catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */}
    }

    return in;
}

bool Dvector::operator==(const Dvector &vect)
{
    for (int index = 0; index<vect.size(); index++) {
        if (vect.get(index) != v[index]) {
            return false;
        }
    }
    return true;
}

void Dvector::resize(int size, double* vect)
{
    // On redimensionne le vecteur
    if (size > v_size) {
        double* new_zone;
        new_zone = new double[size];
        new_zone = (double*) memcpy(new_zone, v, sizeof(double) * v_size);
        delete[] v;
        v = new_zone;
    }
    // On remplit le vecteur
    int index = 0;
    if (vect != 0 && size > v_size) {
        while (index+v_size < size) {
            v[index + v_size] = vect[index];
            index++;
        }
    }
    v_size = size;

}

bool Dvector::isnull()
{
    for (int i = 0; i < v_size; i++) {
        if (v[i] != 0) {
            return false;
        }
    }
    return true;
}
