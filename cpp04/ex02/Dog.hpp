#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *DogBrain;

    public:
        Dog();
        Dog(const Dog& copy);
        Dog &operator=(const Dog& src);
        ~Dog();
        
        void makeSound() const;
};


#endif