# include "Zombie.hpp"

// Creating new instance of class Zombie and allocate it to the heap
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}