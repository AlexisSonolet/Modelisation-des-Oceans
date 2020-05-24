
#include "./test.h"
#include "../src/Dvector.h"
#include <assert.h>
#include <iostream>

using namespace std;

void test_time()
{

	Dvector a(100000000,4);
	Dvector b(100000000,5);
	Dvector c(100000000,6);
	Dvector d(100000000,6);
	Dvector e(100000000,6);

	time_t result = time(nullptr);
	Dvector f = a;
	f = b;
	f = c;
	f = d;
	f = e;
	time_t result_1 = time(nullptr) - result;
	time_t new_result = time(nullptr);
	Dvector g;
	g.assign(a);
	g.assign(b);
	g.assign(c);
	g.assign(d);
	g.assign(e);
	time_t result_2 = time(nullptr) - new_result;
	cout << "Time for memcpy : " << result_1 << " seconds" << endl;
	cout << "Time for manual set: " << result_2 << " seconds" << endl;
}
