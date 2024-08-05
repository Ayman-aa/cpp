# include "Zombie.hpp"

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