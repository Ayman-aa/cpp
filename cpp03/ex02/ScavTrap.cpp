# include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unnamed ScavTrap")
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap named constructor called for " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    *this = other;
    std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) 
        ClapTrap::operator=(other);

    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_name == target)
    {
        std::cout << "Scavtrap " << this->_name << " can't attack itself! Or maybe change the name of the target" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
    {
        std::cout << "Scavtrap " << this->_name << " can't attack. " << (this->_hitPoints == 0 ? "No hit points left!" : "Not enough energy!") << std::endl;
        return ;
    }

    this->_energyPoints--;
    if (this->_energyPoints < 0)
        this->_energyPoints = 0;

    std::cout << "Scavtrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}