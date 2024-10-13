#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base *generate()
{
    int rand = std::rand() % 3;
    switch(rand) {
        case 0: return new classA();
        case 1: return new classB();
        case 2: return new classC();
        default: return NULL; 
    }
}

void identify(Base* p)
{
    if(dynamic_cast<classA*>(p))
        std::cout << "it's class A" << std::endl;
    else if(dynamic_cast<classB*>(p))
        std::cout << "it's class B" << std::endl;
    else if(dynamic_cast<classC*>(p))
        std::cout << "it's class C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<classA&>(p);
        std::cout << "it's class A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {
        try
        {
            dynamic_cast<classB&>(p);
            std::cout << "it's class B" << std::endl;
            return;
        }
        catch (std::exception& e)
        {
            try
            {
                dynamic_cast<classC&>(p);
                std::cout << "it's class C" << std::endl;
                return;
            }
            catch (std::exception& e)
            {
                std::cout << "unknown" << std::endl;
            }
        }
    }
}
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