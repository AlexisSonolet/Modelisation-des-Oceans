#include "src/Dvector.h"
#include "test.h"
void stop(std::string message)
{
    if (message == "") {
        std::cout << "STOP" << std::endl;
    } else {
        std::cout << message << std::endl;
    }

}

int main()
{

    stop("--- Q2 ---");
	test_construct();
	test_random();
	test_copy();
	test_string();

    return 0;
}
