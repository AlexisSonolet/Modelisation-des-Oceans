#include "../test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_construct()
{
	Dvector def;
	cout << "Default constructor size :" << def.size() << endl;
	Dvector filled_vect(5,2);
	assert(filled_vect.size() == 5);
	cout << "We fill a vector of size 5 with 2 and get :" << endl;
	filled_vect.display(cout);
}
