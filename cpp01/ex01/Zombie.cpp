# include "Zombie.hpp"

// Default constructor
Zombie::Zombie()
{
    std::cout  << "The mimic tear is ready" << std::endl;
}

// Constructor
Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << this->_name << " has been summoned" << std::endl;
}

// Deconstructor
Zombie::~Zombie(void)
{
    std::cout << this->_name << " has been demolished" << std::endl;
}

// Method
void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Getter and Setter

std::string Zombie::getName(void)
{
    return (this->_name);
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}