# include "ScavTrap.hpp"

int main(void)
{

    ClapTrap clapTrap("Clapy");
    ScavTrap scavtrap("Scavy");
    ClapTrap clapTrap3 ("Clapu");

    ClapTrap *test = &scavtrap;
    test->attack(clapTrap.getName());

    return 0;
}