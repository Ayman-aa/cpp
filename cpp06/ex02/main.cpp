#include "Base.hpp"

int main()
{
    std::srand(std::time(0));

    std::cout << "generating..." << std::endl;
    Base *base = generate();

    std::cout <<"identifying by pointer" << std::endl;
    identify(base);

    std::cout << "identifying by reference" << std::endl;
    identify(*base);

    std::cout << "deleting..." << std::endl;
    delete base;

    std::cout << "Done" << std::endl;
    return 0;
}