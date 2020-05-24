
#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_operators()
{
	cout << "Test Operators" << endl;
	Dvector a(4,3);
	Dvector b = a + 4;
	for(int i = 0; i < b.size(); i++)
	{
		assert(b.get(i) == 7);
	}
	Dvector c = a - b;
	for(int i = 0; i < c.size(); i++)
	{
		assert(c.get(i) == -4);
	}
	for(int i = 0; i < c.size(); i++)
	{
		assert((-c).get(i) == 4);
	}
	cout << "Operators : OK" << endl;
}
