# include "ScavTrap.hpp"

int main(void)
{

    ClapTrap clapTrap("Clapy");
    ScavTrap scavtrap("Scavy");
    ClapTrap clapTrap3 ("Clapu");

    clapTrap.setAttackDamage(5);
    clapTrap.attack(scavtrap.getName());
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(3);

    scavtrap.attack(clapTrap3.getName());
    clapTrap3.takeDamage(scavtrap.getAttackDamage());
    clapTrap3.beRepaired(3);

    clapTrap3.setAttackDamage(11);
    clapTrap3.attack(clapTrap.getName());
    clapTrap.takeDamage(11);
    clapTrap.beRepaired(3);
    scavtrap.guardGate();

    return 0;
}