#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &wrongCat);
        WrongCat &operator=(const WrongCat &wrongCat);
        virtual ~WrongCat();
        void makeSound() const;
};

#endif 