#include "MutantStack.hpp"
#include <iostream>

int main()
{
   std::cout << "Test inserting" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(20);
    mstack.push(42);
    mstack.push(69);
    mstack.push(84);
    mstack.push(100);
    std::cout << "Test iterators" << std::endl;
    std::cout << "It contains: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Test pop" << std::endl;
    mstack.pop();
    std::cout << "It contains: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Test top" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Test size" << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Test empty" << std::endl;
    if(mstack.empty())
        std::cout << "Stack empty" << std::endl;
    else
        std::cout << "Stack not empty" << std::endl;
}
