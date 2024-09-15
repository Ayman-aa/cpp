#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";

    DogBrain = new Brain();

    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    type = other.type;
    DogBrain = new Brain(*other.DogBrain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        delete DogBrain;
        DogBrain = new Brain(*other.DogBrain);
        type = other.type;
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete DogBrain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}