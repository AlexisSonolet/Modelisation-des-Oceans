#pragma once

#include <iostream>
#include <complex>
#include <fstream>
#include <ostream>
#include <istream>
#include <string.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

template<typename T>
class ComplexVector
{
    public:
        ComplexVector();
        ComplexVector(int size, T value = T(0,0));
        ComplexVector(ComplexVector const& vect);
        ComplexVector(std::string fichier);
        ~ComplexVector();
        void display(std::ostream& str);
        int size() const;
        void fillRandomly();
        T get(int index) const;
        void set(int index, T value);
        void set_size(int size);
        void set_v(T* vect);
        T* get_v() const;
		ComplexVector get_even() const;
		ComplexVector get_odd() const;
        ComplexVector operator=(const ComplexVector &vect);
        ComplexVector operator+=(const ComplexVector &vect);
        ComplexVector operator-=(const ComplexVector &vect);
        ComplexVector operator*=(int i);
        ComplexVector operator*=(const ComplexVector &vect);
        ComplexVector operator/=(int i);
        ComplexVector operator+(int i);
        ComplexVector operator-(int i);
        ComplexVector operator*(int i);
        T operator*(const ComplexVector &vect);
        ComplexVector operator/(int i);
        ComplexVector operator+(ComplexVector &vect);
        ComplexVector operator-(ComplexVector &vect);
        ComplexVector operator-();
        bool operator==(const ComplexVector &vect);
        void resize(int size, T* vect = 0);
        bool isnull();

    private:
        T* v;
        int v_size;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const ComplexVector<T>& v);
template<typename T>
std::istream& operator>>(std::istream& in, ComplexVector<T>& v);

// === Math constants ===
#define g 9.81
#define M_PI 3.14159265358979323846264338327950288
#define M_PI_2 1.57079632679489661923132169163975144

template<typename T>
ComplexVector<T>::ComplexVector()
{
    v = new T[0]; // v vecteur de taille définie
    v_size = 0;
};

template<typename T>
ComplexVector<T>::ComplexVector(int size, T value)
{
    v = new T[size]; // v vecteur de taille définie
    v_size = size;
    for (int i = 0; i < size; i++)
        v[i] = value;
};

template<typename T>
ComplexVector<T>::ComplexVector(ComplexVector const& vect)
{
    v = new T[vect.v_size];
    v_size = vect.v_size;
    for (int i = 0; i < vect.v_size; i++)
        v[i] = *(vect.v + i);
};

template<typename T>
ComplexVector<T>::ComplexVector(string fichier)
{
    ifstream flux(fichier);
    double n; // cast en double de la ligne courante
    double m; // pour la partie imaginaire
	int vect_size = 0;
	complex<double> ex;
	std::string::size_type sz; 
    if(flux)
    {
		cout << "flux" << endl;
        string ligne;
        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            try {
                n = stod(ligne, &sz);
				if(typeid(T) == typeid(ex)){
					m = stod(ligne.substr(sz));
				}
                vect_size++;
            }
            catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */ }
        }
    }
    else
    {
        v = new T[0];
        v_size = 0;
        return;
    }
    flux.clear(); flux.seekg(0, flux.beg); // Réinitialiser la lecture du flux
    
    v = new T[vect_size];
    v_size = vect_size;
    // On remplit le vecteur
    int i = 0;
    string ligne;
    while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
    {
        try {
			n = stod(ligne, &sz);
			if(typeid(T) == typeid(ex)){
				m = stod(ligne.substr(sz));
				v[i] = T(n,m);
			}
			else{
				v[i] = n;
			}
            i++;
        }
        catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */ }
    }
}

template<typename T>
ComplexVector<T>::~ComplexVector()
{
    delete[] v;
};

template<typename T>
void ComplexVector<T>::display(ostream& str)
{
    for (long unsigned int i = 0; i < v_size; i++) {
        str << v[i] << endl;
    }
};

template<typename T>
int ComplexVector<T>::size() const
{
    return v_size;
};

template<typename T>
void ComplexVector<T>::fillRandomly()
{
	complex<double> ex;
	if(typeid(T) == typeid(ex)){
		for(long unsigned int i = 0; i<v_size; i++) {
			// fill with random
			v[i] = complex<double>((double)rand()/RAND_MAX, (double)rand()/RAND_MAX);	
		}
	}
	else{
		for(long unsigned int i = 0; i<v_size; i++) {
			// fill with random
			v[i] = (T) rand() / (T) RAND_MAX;
		}
	}
};

template<typename T>
T ComplexVector<T>::get(int index) const
{
    if (index >= v_size) {
        throw string("Error : cannot access to an index above the size of the vector");
        return 0;
    } else {
        return v[index];
    }
}

template<typename T>
void ComplexVector<T>::set(int index, T value)
{
    if (index >= v_size) {
        throw string("Error : cannot access to an index above the size of the vector");
    }

    v[index] = value;
}

template<typename T>
void ComplexVector<T>::set_size(int size)
{
    v_size = size;
}

template<typename T>
void ComplexVector<T>::set_v(T* vect)
{
    v = vect;
}

template<typename T>
T* ComplexVector<T>::get_v() const
{
    return v;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::get_even() const
{
	ComplexVector even((int)((v_size-1)/2) + 1);
	for(int index = 0; index < v_size; index+=2)
	{
		even.set(index/2, v[index]);
	}
	return even;	
}

template<typename T>
ComplexVector<T> ComplexVector<T>::get_odd() const
{
	ComplexVector odd((int)(v_size/2));
	for(int index = 1; index < v_size; index+=2)
	{
		odd.set((int)(index/2), v[index]);
	}
	return odd;	
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator=(const ComplexVector &vect)
{
    // Si le vecteur a déjà été assigné, il faut le libérer
    delete[] v;
    v_size = vect.v_size;
    v = new T[v_size];
    memcpy(v, vect.v, v_size * sizeof(T));

    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator+=(const ComplexVector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] += vect.get(index);
    }
    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator-=(const ComplexVector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] -= vect.get(index);
    }
    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator*=(int i)
{
    for (int index = 0; index<v_size; index++) {
        v[index] *= i;
    }
    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator*=(const ComplexVector &vect)
{
    if (v_size != vect.v_size) {
        throw string("Error : vectors of different sizes");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] *= vect.v[index];
    }
    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator/=(int i)
{
    if (i == 0) {
        throw string("NullDivisionError : cannot divide by 0");
    }
    for (int index = 0; index<v_size; index++) {
        v[index] /= i;
    }
    return *this;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator+(int i)
{
    ComplexVector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] + (T) i);
    }
    return vect;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator-(int i)
{
    ComplexVector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] - (T) i);
    }
    return vect;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator*(int i)
{
    ComplexVector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] * i);
    }
    return vect;
}

template<typename T>
T ComplexVector<T>::operator*(const ComplexVector &vector)
{
    // Produit scalaire
    if (v_size != vector.v_size) {
        throw string("Error : vectors of different sizes");
    }
    T value;
    for (int index = 0; index<v_size; index++) {
        value += index, v[index] * vector.v[index];
    }
    return value;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator/(int i)
{
    if (i == 0) {
        throw string("NullDivisionError : cannot divide by 0");
    }

    ComplexVector vect(v_size);
    for (int index = 0; index<v_size; index++) {
        vect.set(index, v[index] / i);
    }
    return vect;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator+(ComplexVector &vect)
{
    if (vect.v_size != v_size) {
        throw string("Error : size doesn't match");
    }
    ComplexVector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, v[index] + vect.get(index));
    }
    return vector;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator-(ComplexVector &vect)
{
    if (vect.v_size != v_size) {
        throw string("Error : size doesn't match");
    }
    ComplexVector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, v[index] - vect.get(index));
    }
    return vector;
}

template<typename T>
ComplexVector<T> ComplexVector<T>::operator-()
{
    ComplexVector vector(v_size);
    for (int index = 0; index<v_size; index++) {
        vector.set(index, -v[index]);
    }
    return vector;
}

template<typename T>
ostream& operator<<(ostream& out, const ComplexVector<T>& v)
{
    for (long unsigned int i = 0; i<v.size() ; i++) {
        out << v.get(i) << endl;
    }
    return out;
}

template<typename T>
istream& operator>>(istream& in, ComplexVector<T>& v)
{
    int index = 0; // taille de vect

    string input;
    double n;
	double m;
	complex<double> ex;
	while (getline(cin, input) && !input.empty()) {
        try {
            stringstream ss(input);
            ss >> n;
			if(typeid(T) == typeid(ex))
			{
				ss >> m;
				v.set(index, complex<double>(n,m));
			}
			else
			{
				v.set(index, n);
			}
			index++;
        }
        catch(...) {/* TODO : éviter les "..." => trouver la bonne erreur */}
    }

    return in;
}

template<typename T>
bool ComplexVector<T>::operator==(const ComplexVector &vect)
{
    for (int index = 0; index<vect.size(); index++) {
        if (vect.get(index) != v[index]) {
            return false;
        }
    }
    return true;
}

template<typename T>
void ComplexVector<T>::resize(int size, T* vect)
{
    // On redimensionne le vecteur
    if (size > v_size) {
        double* new_zone;
        new_zone = new T[size];
        new_zone = (T*) memcpy(new_zone, v, sizeof(T) * v_size);
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

template<typename T>
bool ComplexVector<T>::isnull()
{
    for (int i = 0; i < v_size; i++) {
        if (v[i] != 0) {
            return false;
        }
    }
    return true;
}

