#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int> l;

    for (int i = 0; i < 50; i += 2) {
        ;
        l.push_back(i);
    }

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    std::cout << "vector: ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "list: ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "the value " << *it << " found" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::list<int>::iterator it = easyfind(l, 1);
        std::cout << "the value " << *it << " found" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}