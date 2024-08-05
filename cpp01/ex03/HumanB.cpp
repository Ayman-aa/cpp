# include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
    std::cout << "HumanB created under the name of : " << _name << " and he's unarmed"<< std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name <<" dissmised" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << (!this->_weapon ? "fists" : this->_weapon->getType()) << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
    std::cout << this->_name << " got armed with " << this->_weapon->getType() << std::endl;
}
