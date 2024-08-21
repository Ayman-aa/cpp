# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{

    ClapTrap clapTrap("Clapy");
    ScavTrap scavtrap("Scavy");
    FragTrap fragTrap ("Fragu");

    clapTrap.setAttackDamage(5);
    clapTrap.attack(scavtrap.getName());
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(3);

    scavtrap.attack(fragTrap.getName());
    fragTrap.takeDamage(scavtrap.getAttackDamage());
    fragTrap.beRepaired(3);

    fragTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(fragTrap.getAttackDamage());
    clapTrap.beRepaired(3);
    scavtrap.guardGate();
    fragTrap.highFivesGuys();

    return 0;
}