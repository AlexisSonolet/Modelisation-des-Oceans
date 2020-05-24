#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_random()
{
	Dvector random(5);
	cout << "Default constructor size :" << random.size() << endl;
	random.fillRandomly();
	cout << "Random vector of size 5" << endl;
	random.display(cout);
}
