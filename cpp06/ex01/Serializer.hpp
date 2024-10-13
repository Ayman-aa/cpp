#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstring>
#include <stdint.h>

struct Data
{
    int data;
};
class Serializer
{
    private:
        Serializer();
    
    public:
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif