#include <iostream>
#include "Dvector.h"
#include "../test/test.h"

using namespace std;

int main() {
	test_access();
	test_affect();
	test_operators();
	test_flux();
	test_resize_equal();
	test_time();
	return 0;
}
