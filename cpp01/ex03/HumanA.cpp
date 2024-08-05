#include "HumanA.hpp"

//using initializer list for fewer lines I guess..
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << "HumanA created under the name of : " << _name << " and armed with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name <<" dissmised" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}