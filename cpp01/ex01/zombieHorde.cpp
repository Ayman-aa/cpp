# include "Zombie.hpp"

// Creating N instances of class Zombie and allocate it to the heap
Zombie* zombieHorde(int N,std::string name)
{
    if (N < 0)
        return (NULL);
    
    // Try to allocate memory
    Zombie* horde = new(std::nothrow) Zombie[N];
    if (horde == NULL)
    {
        std::cerr << "Error: Memory allocation failed." << std::endl;
        return NULL;
    }

    for(int i = 0; i < N; i++)
        horde[i].setName(name);

    return (horde);
}