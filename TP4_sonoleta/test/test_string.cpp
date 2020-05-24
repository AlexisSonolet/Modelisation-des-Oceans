#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_string()
{
	cout << "TEST STRING" << endl;
	Dvector string("./../test/tp1_test0.txt");
	string.display(cout);
}
