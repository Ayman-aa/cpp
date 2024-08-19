# include "Zombie.hpp"

// Creating new instance of class Zombie and allocate it to the heap and return the pointer
Zombie* newZombie(std::string name)
{
    return (new Zombie(name));
}