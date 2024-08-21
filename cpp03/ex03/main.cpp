# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int main(void)
{

    ClapTrap clapTrap("Clapy");
    ScavTrap scavtrap("Scavy");
    FragTrap fragTrap ("Fragu");
    DiamondTrap diamondTrap("Diama");

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

    diamondTrap.attack(fragTrap.getName());
    diamondTrap.attack(scavtrap.getName());
    diamondTrap.attack(clapTrap.getName());
    fragTrap.takeDamage(diamondTrap.getAttackDamage());
    scavtrap.takeDamage(diamondTrap.getAttackDamage());
    clapTrap.takeDamage(diamondTrap.getAttackDamage());

    diamondTrap.whoAmI();
    scavtrap.guardGate();
    fragTrap.highFivesGuys();

    return 0;
}