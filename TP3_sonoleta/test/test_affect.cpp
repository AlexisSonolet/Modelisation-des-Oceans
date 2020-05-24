#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_affect()
{
	cout << "Test Affect" << endl;
	Dvector to_affect(6,3);
	cout << "We created the following vector" << endl;
	cout << to_affect << endl;
	Dvector affected(8);
	assert(affected.size() == 8);
	affected = to_affect;
	assert(affected.size() == 6);
	assert(affected == to_affect);
	cout << "We affect this vector to a new vector (of different size)" << endl;
	cout << affected << endl;
	affected(2) = 1;
	for(int i = 0; i < to_affect.size(); i++)
	{
		assert(to_affect(i) == 3);
	}
}
