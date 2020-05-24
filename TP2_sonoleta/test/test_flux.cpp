
#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_flux()
{
	cout << "Test flux" << endl << "Please enter a vector of size 5, then press ENTER with no input :" << endl;
	Dvector in_vect(5);
	cin >> in_vect;
	cout << "You just entered the vector :" << endl << in_vect << endl;
}
