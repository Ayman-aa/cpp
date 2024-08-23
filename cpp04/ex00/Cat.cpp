#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat){}

Cat &Cat::operator=(const Cat &cat)
{
    Animal::operator=(cat);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow" << std::endl;
}