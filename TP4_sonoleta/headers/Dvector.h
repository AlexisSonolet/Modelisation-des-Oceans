#pragma once

#include <iostream>

class Dvector
{
    public:
        Dvector();
        Dvector(int size, double value=0);
        Dvector(Dvector const& vect);
        Dvector(std::string fichier);
        ~Dvector();
        void display(std::ostream& str);
        int size() const;
        void fillRandomly();
        double get(int index) const;
        void set(int index, double value);
        void set_size(int size);
        void set_v(double* vect);
        double* get_v() const;
		Dvector get_even() const;
		Dvector get_odd() const;
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
        void resize(int size, double* vect = 0);
        bool isnull();

    private:
        double* v;
        int v_size;
};

std::ostream& operator<<(std::ostream& out, const Dvector& v);
std::istream& operator>>(std::istream& in, Dvector& v);

// === Math constants ===
#define g 9.81
#define M_PI 3.14159265358979323846264338327950288