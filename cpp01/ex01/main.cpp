# include "Zombie.hpp"

// Prototypes of functions needed
Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	std::string	name = "Boat necromancer";
	int			num = 3;

	std::cout << "Initializing Zombie Horde" << std::endl;
	Zombie	*horde = zombieHorde(num, name);

	std::cout << "Announcing the horde" << std::endl;
	for (int i = 0; i < num; i++)
		horde[i].announce();

	std::cout << "Killing the horde" << std::endl;
	delete[] horde;
	return (0);
}