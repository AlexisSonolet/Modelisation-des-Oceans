#pragma once

#include <iostream>

class Dvector
{
    public :
        Dvector();
        Dvector(int size, int value=0);
        Dvector(Dvector const& vect);
        Dvector(std::string fichier);
        ~Dvector();
        void display(std::ostream& str);
        int size();
        void fillRandomly();
        double get(int index);
        void set(int index, double value);
        Dvector operator=(const Dvector &vect);
        Dvector operator+=(Dvector &vect);
        Dvector operator-=(Dvector &vect);
        Dvector operator*=(int i);
        Dvector operator/=(int i);
        Dvector operator+(int i);
        Dvector operator-(int i);
        Dvector operator*(int i);
        Dvector operator/(int i);
        Dvector operator+(Dvector &vect);
        Dvector operator-(Dvector &vect);
        Dvector operator-();

    private:
        double* v;
        int v_size;
};