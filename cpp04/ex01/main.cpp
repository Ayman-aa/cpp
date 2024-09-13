#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    // Create half Dogs and half Cats
    for (int i = 0; i < numAnimals / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i)
    {
        animals[i] = new Cat();
    }

    // Demonstrate deep copy
    {
        Dog originalDog;
        Dog copyDog = originalDog;  // This should trigger a deep copy
    }  // Both dogs go out of scope here, testing proper destruction

    // Delete all animals
    for (int i = 0; i < numAnimals; ++i)
    {
        delete animals[i];
    }

    // Additional test for deep copy (optional, but good for verification)
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1);
    delete dog1;
    delete dog2;   
}