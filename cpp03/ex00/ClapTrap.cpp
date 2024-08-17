#include "ClapTrap.hpp"
#include <iostream>

/* Constructors & Destructors */
ClapTrap::ClapTrap(void) : _name("unidentified"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called for '" << this->_name << "'" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called for '" << this->_name << "'" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    *this = clapTrap;
    std::cout << "ClapTrap copy constructor called for '" << this->_name << "'" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called for '" << this->_name << "'" << std::endl;
}

/* Member functions */
void ClapTrap::attack(const std::string& target)
{
    if(this->_name == target){
        std::cout << "ClapTrap " << this->_name << " can't attack itself! Or maybe change the name of the target" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't attack. " << (this->_hitPoints == 0 ? "No hit points left!" : "Not enough energy!") << std::endl;
        return ;
    }

    this->_energyPoints--;
    if (this->_energyPoints < 0)
        this->_energyPoints = 0;

    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
        return;
    }
    if (amount >= (unsigned int)this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage and is destroyed!" << std::endl;
    }
    else
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage, reducing hit points to " << this->_hitPoints << std::endl;
    }
    std::cout <<" this is the amount : " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0 || this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " can't be repaired. " << (this->_hitPoints == 0 ? "No hit points left!" : "Not enough energy!") << std::endl;
        return;
    }

    this->_hitPoints += amount;
    this->_energyPoints--;
    if (this->_energyPoints < 0)
        this->_energyPoints = 0;

    std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount << " hit points. Now at " << this->_hitPoints << " hit points." << std::endl;
}

/* Overloaded operators */
ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap)
{
    if (this != &clapTrap)
    {
        this->_name = clapTrap._name;
        this->_hitPoints = clapTrap._hitPoints;
        this->_energyPoints = clapTrap._energyPoints;
        this->_attackDamage = clapTrap._attackDamage;
    }
    return (*this);
}

/* Getters & Setters */
std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    std::cout << "ClapTrap " << this->_name << " sets attack damage to " << attackDamage << std::endl;
    this->_attackDamage = attackDamage;
}
