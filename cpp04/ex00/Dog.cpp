#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog){}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}