#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        virtual ~Cat();

        virtual void makeSound() const;
};

#endif