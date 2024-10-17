#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>

template <typename T, typename Fun> void iter(T *array, size_t length, Fun f)
{
    if (!array || !f)
        return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T> void print(T const &x)
{
    std::cout << x << " ";
}

#endif