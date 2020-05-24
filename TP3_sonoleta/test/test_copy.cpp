#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_copy()
{
	Dvector toCopy(6);
	toCopy.fillRandomly();
	Dvector copy(toCopy);
	cout << "Vector to copy" << endl;
	toCopy.display(cout);
	cout << "New vector (copy of previous)" << endl;
	copy.display(cout);
	cout << "We modify the copy and check if it changes the old vector" << endl;
	copy.fillRandomly();
	cout << "Old vector :"<< endl;
	toCopy.display(cout);
	cout << "New vector (which was a copy):" << endl;
	copy.display(cout);
}
