# include "Zombie.hpp"

// Creating new instance of class Zombie and in the stack within the function scope
void    randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();

    // allocating in the heap then expplicitly deleting it
    // Zombie *zombie = new Zombie(name);
    // zombie->announce();
    // delete zombie;    
}