#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Dog dog;
    {
        Dog dog2 = dog;
    }
}