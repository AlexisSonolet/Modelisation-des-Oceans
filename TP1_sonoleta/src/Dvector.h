#pragma once

#include <iostream>

class Dvector
{
    public :
        Dvector();
        Dvector(int size, int value=0);
        ~Dvector();
        void display(std::ostream& str);
    
    private:
        double* v;
};