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
    Dvector v2;
    v2 = v1;
    v2.display(cout);
    Dvector v3(2, 5);
    v3 = v1;
    v3.display(cout);

    cout << "--- Q3 ---" << endl;
    cout << "v1 += v1" << endl;
    v1 += v1;
    v1.display(cout);
    cout << "v2 -= v2" << endl;
    v2 -= v2;
    v2.display(cout);
    
    cout << "--- Q4 ---" << endl;
    Dvector v4, v5, v6;
    cout << "v4 = v1 + 1" << endl;
    v4 = v1+1;
    v4.display(cout);
    cout << "v5 = v4 * 10" << endl;
    v5 = v4*10;
    v5.display(cout);
    cout << "v6 = v5 - v4" << endl;
    v6 = v5 - v4;
    v6.display(cout);
    cout << "v5 = -v6" << endl;
    v5 = -v6;
    v5.display(cout);
    /* Erreurs
    Dvector aa(2, 5), bb(3, 7), cc;
    cc = aa + bb;
    cc.display(cout);
    */

    return 0;
}