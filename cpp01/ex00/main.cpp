# include "Zombie.hpp"

// Prototypes of functions needed
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int main(void)
{
    // Creating an instance
    std::cout << "Zombie incarnation spell, summoning Godrick" << std::endl;
    Zombie *godrick = newZombie("Godrick");
    godrick->announce();

    // Creating another instance
    std::cout << "Zombie incarnation spell, summoning Negan" << std::endl;
    randomChump("Negan");

    delete godrick;
}