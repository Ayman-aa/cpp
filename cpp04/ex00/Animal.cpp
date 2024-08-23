# include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal type constructor called for "<< type << std::endl;
}

Animal::~Animal()
{
    if(type != "")
        std::cout << "Animal type destructor called for " << type << std::endl;
    else
        std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.type){}

Animal &Animal::operator=(const Animal &animal)
{
    if (this != &animal) 
        type = animal.type;
    return *this;
}

std::string Animal::getType() const { return this->type; }

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}