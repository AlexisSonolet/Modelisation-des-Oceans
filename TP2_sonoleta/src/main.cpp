#include <iostream>
#include "Dvector.h"

using namespace std;

int main() {
    cout << "--- Q1 ---" << endl;
    cout << "Vecteur v1" << endl;
    Dvector v1(5);
    v1.fillRandomly();
    v1.display(cout);
    cout << "v1[2] =" << endl << v1.get(2) << endl;

    cout << "--- Q2 ---" << endl;
    Dvector v2;
    v2 = v1;
    cout << "v2; v2 = v1; v2 = " << endl;
    v2.display(cout);
    Dvector v3(2, 5);
    v3 = v1;
    cout << "v3(2, 5); v3 = v1; v3 = " << endl;
    v3.display(cout);

    cout << "--- Q3 ---" << endl;
    cout << "v1 += v1" << endl;
    v1 += v1;
    v1.display(cout);
    cout << "v1 -= v2; v1 = " << endl;
    v1 -= v2;
    v1.display(cout);
    
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
    
    cout << "--- Q5 ---" << endl;
    cout << "taille : " << v1.size() << endl;
    cin >> v1;
    cout << "v1 = " << endl << v1 << endl;

    cout << "--- Q6 ---" << endl;
    Dvector v7(v1), v8;
    v8.fillRandomly();
    if (v1 == v7) {
        printf("ok1\n");
    } else {
        printf("pasok1");
    }
    /* pas implémenté
    if (v1 != v8) {
        printf("ok2\n");
    } else {
        printf("pasok2");
    }
    */

    cout << "--- Q7 ---" << endl;
    Dvector a1(5,2), a2(2,6);
    a1.resize(3);
    cout << "a1(5, 2); a1.resize(3); a1 = " << endl << a1 << endl;
    double tab[2] = {11, 32};
    a2.resize(4, tab);
    cout << "a2(2, 6); a2.resize(4, [11, 32]); a2 = " << endl;
    cout << a2 << endl;

    return 0;
}