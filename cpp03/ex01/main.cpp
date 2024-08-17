# include "ClapTrap.hpp"

int main(void)
{

    ClapTrap clapTrap("Clapy");
    ClapTrap clapTrap2("Clapo");
    ClapTrap clapTrap3 ("Clapu");

    clapTrap.setAttackDamage(5);
    clapTrap.attack(clapTrap2.getName());
    clapTrap2.takeDamage(5);
    clapTrap2.beRepaired(3);

    clapTrap2.setAttackDamage(2);
    clapTrap2.attack(clapTrap3.getName());
    clapTrap3.takeDamage(2);
    clapTrap3.beRepaired(3);

    clapTrap3.setAttackDamage(11);
    clapTrap3.attack(clapTrap.getName());
    clapTrap.takeDamage(11);
    clapTrap.beRepaired(3);

    return 0;
}