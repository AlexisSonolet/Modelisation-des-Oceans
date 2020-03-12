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
    
    private:
        double* v;
        int v_size;
};