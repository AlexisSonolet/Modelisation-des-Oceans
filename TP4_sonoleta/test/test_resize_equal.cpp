#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_resize_equal()
{
	cout << "Test Resize" << endl;
	Dvector toResize(5,2);
	double tab[2] = {11, 32};
	Dvector b(7, 2);
	b.set(5, 11);
	b.set(6, 32);
	toResize.resize(7, tab);
	assert(toResize == b);
	cout << "Test resize and equals OK" << endl;
}
