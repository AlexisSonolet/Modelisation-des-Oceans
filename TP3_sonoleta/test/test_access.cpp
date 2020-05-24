#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_access()
{
	cout << "Test Access" << endl;
	Dvector access(5, 2);
	cout << "Before changing index 3:" << endl;
	access.display(cout);
	cout << "After changing index 3:" << endl;
	access(3) = 3;
	access.display(cout);
}
