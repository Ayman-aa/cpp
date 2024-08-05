# include "Zombie.hpp"

// Creating N instances of class Zombie and allocate it to the heap
Zombie* zombieHorde(int N,std::string name)
{
    if (N < 0)
        return (NULL);
    
    Zombie *horde = new Zombie[N];

    for(int i = 0; i < N; i++)
        horde[i].setName(name);

    return (horde);
}