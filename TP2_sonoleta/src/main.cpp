#include <iostream>
#include "Dvector.h"

using namespace std;

int main() {
    cout << "--- Q1 ---" << endl;
    cout << "Vecteur v1" << endl;
    Dvector v1(5);
    v1.fillRandomly();
    v1.display(cout);
    cout << "Troisième élément : ";
    cout << v1.get(3 - 1) << endl;

    cout << "--- Q2 ---" << endl;
    
    return 0;
}