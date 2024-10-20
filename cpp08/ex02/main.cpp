#include "MutantStack.hpp"
#include <iostream>

int main()
{
    // Test with default deque container
    std::cout << "Testing MutantStack with std::deque container" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl; 

    mstack.pop();  

    std::cout << "Stack size after pop: " << mstack.size() << std::endl; 

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack contents: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    return 0;
}
