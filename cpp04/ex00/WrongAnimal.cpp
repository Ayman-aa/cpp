#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal type constructor called for "<< type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) : type(wrongAnimal.type){}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
    if (this != &wrongAnimal) 
        this->type = wrongAnimal.type;
    return *this;
}

std::string WrongAnimal::getType() const { return this->type; } 

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}