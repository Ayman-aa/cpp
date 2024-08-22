# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unidentified_clap_name"), ScavTrap(), FragTrap()
{
    this->_name = "unidentified";
    this->_hitPoints = this->FragTrap::_hitPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackDamage = this->FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name.empty() ? "unidentified_clap_name" : name + "_clap_name"), ScavTrap(), FragTrap() 
{
    this->_name = name.empty() ? "unidentified" : name;
    this->_hitPoints = this->FragTrap::_hitPoints;
    this->_energyPoints = this->ScavTrap::_energyPoints;
    this->_attackDamage = this->FragTrap::_attackDamage;
    std::cout << "DiamondTrap named constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap assignment operator called for " << this->_name << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}