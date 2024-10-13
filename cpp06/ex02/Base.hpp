#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <ctime>
#include <cstdlib>
class Base
{
    public:
        virtual ~Base();
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

class classA : public Base{};
class classB : public Base{};
class classC : public Base{};


#endif