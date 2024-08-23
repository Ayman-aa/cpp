#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testSubject(void) 
{
	std::cout << "Running Subjects Tests" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}

void	testWrongCat(void)
{
	std::cout <<"Running WrongCat Tests" << std::endl;
	const WrongAnimal*	meta = new WrongAnimal();
	const Animal*		l = new Dog();
	const WrongAnimal*	k = new WrongCat();

	std::cout << l->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	l->makeSound();
	k->makeSound();
	meta->makeSound();

	delete k;
	delete l;
	delete meta;
}

int	main()
{
	testSubject();
	testWrongCat();
}