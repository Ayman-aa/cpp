#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";

    CatBrain = new Brain();

    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &other)
{
    type = other.type;
    CatBrain = new Brain(*other.CatBrain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
        delete CatBrain;
        CatBrain = new Brain(*other.CatBrain);
        type = other.type;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete CatBrain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}