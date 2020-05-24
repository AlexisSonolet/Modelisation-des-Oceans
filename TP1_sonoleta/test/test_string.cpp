#include "../test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_string()
{
	Dvector string("./tp1_test1.txt");
	string.display(cout);
}
