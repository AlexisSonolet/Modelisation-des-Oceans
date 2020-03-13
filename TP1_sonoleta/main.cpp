#include "src/Dvector.h"

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
    stop("--- Q1 ---");
    Dvector v1, v2(5, 3);
    v1.display(std::cout);
    stop("");
    v2.display(std::cout);

    stop("--- Q2 ---");
    std::cout << v2.size() << std::endl;
    v2.fillRandomly();
    stop("");
    v2.display(std::cout);
    stop("création de v3");
    Dvector v3(v2);
    v3.display(std::cout);
    v3.fillRandomly();
    stop("test : vraie recopie");
    stop("nouveau v3");
    v3.display(std::cout);
    stop("v2");
    v2.display(std::cout);
    
    stop("--- Q3 ---");
    stop("test1");
    Dvector v4("./../test/tp1_test1.txt");
    v4.display(std::cout);
    stop("fichier inexistant");
    Dvector v5("./../test/tp1_test0.txt");
    v5.display(std::cout);
    std::cout << "taille : ";
    std::cout << v5.size() << std::endl;

    return 0;
}