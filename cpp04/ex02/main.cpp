#include "Cat.hpp"
#include "Dog.hpp"

int main()
{   
    // Animal a;  // Error: cannot instantiate abstract class
    Animal* animal = new Dog();  
    animal->makeSound(); 
    delete animal;
    return 0;
}