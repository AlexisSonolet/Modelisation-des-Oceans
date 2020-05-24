
#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_self_operators()
{
	cout << "TEST SELF OPERATORS (+=, -= , *=, /=)" << endl;
	Dvector a(4,2);
	Dvector	b(4,1);
	cout << a << endl;
	cout << b << endl;
	a -= Dvector(4,3);
	for(int i = 0; i < a.size(); i++)
	{
		assert(a.get(i) == -1);
	}	
	a += 2;
	for(int i = 0; i < a.size(); i++)
	{
		assert(a(i) == 1);
	}
	a -= 5;
	for(int i = 0; i < a.size(); i++)
	{
		assert(a(i) == -4);
	}
	a *= 2;
	for(int i = 0; i < a.size(); i++)
	{
		assert(a(i) == -8);
	}
	a /= 4;
	for(int i = 0; i < a.size(); i++)
	{
		assert(a(i) == -2);
	}
}
