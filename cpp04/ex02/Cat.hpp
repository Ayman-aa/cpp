#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *CatBrain;
	public:
		Cat();
		Cat(const Cat& copy);
		Cat &operator=(const Cat& src);
		~Cat();
		
		void makeSound() const;
};
#endif