#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <typename T> class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        Array &operator=(Array const &other);
        T &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;
        unsigned int size() const;
        ~Array();
};

template <typename T> Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = T();
}

template <typename T> Array<T>::Array(Array const &other) : _array(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T> Array<T> &Array<T>::operator=(Array const &other)
{
    if (this == &other)
        return *this;
    if (_array)
        delete[] _array;
    _array = new T[other._size];
    _size = other._size;
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
    return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int i)
{
    if (i < 0 || static_cast<unsigned int>(i) >= _size)
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template <typename T> const T &Array<T>::operator[](unsigned int i) const
{
    if (i < 0 || static_cast<unsigned int>(i) >= _size)
        throw std::out_of_range("Index out of range");
    return _array[i];
}

template <typename T> unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T> Array<T>::~Array()
{
    delete[] _array;
}

#endif