# include "Zombie.hpp"

// Creating new instance of class Zombie and storing in the heap within the function scope
void    randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}