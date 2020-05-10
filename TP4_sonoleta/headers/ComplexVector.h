#pragma once

#include <iostream>

template<typename T>
class ComplexVector
{
    public:
        ComplexVector();
        ComplexVector(int size, int value=0);
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