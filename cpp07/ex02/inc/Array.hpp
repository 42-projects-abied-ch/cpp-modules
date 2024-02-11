#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <ostream>
# pragma once

# include <iostream>

template <class T>
class Array
{
    public:

        Array();
        Array(size_t i);
        Array(const Array<T> &other);
        ~Array();

        Array<T>    &operator = (const Array<T> &other);
        T           &operator [] (size_t i);

        void        printArray(std::ostream &out) const;

        size_t      size() const;

        class IndexOutOfBounds : public std::exception
        {
            virtual const char  *what() const throw();
        };

    protected:

        T           *arr;
        size_t      arrSize;
};

template <class T>
std::ostream    &operator << (std::ostream &out, const Array<T> &obj)
{
    obj.printArray(out);
    return out;
}

template <class T>
const char  *Array<T>::IndexOutOfBounds::what() const throw()
{
    return "Error: Index Out Of Bounds";
}

template <class T>
Array<T>::Array() : arr(new T[0]), arrSize(0)
{
    
}

template <class T>
Array<T>::Array(size_t size)
{
    this->arrSize = size;
    this->arr = new T[size];
    for (size_t i = 0; i < size; i++)
        this->arr[i] = T();
}

template <class T>
Array<T>::Array(const Array &other)
{
    this->arr = NULL;
    operator = (other);
}

template <class T>
Array<T>::~Array()
{
    delete[] this->arr;
}

template <class T>
Array<T>    &Array<T>::operator = (const Array<T> &other)
{
    if (this->arr != NULL)
        delete[] this->arr;
    this->arrSize = other.arrSize;
    this->arr = new T[this->arrSize];
    for (size_t i = 0; i < this->arrSize; i++)
        this->arr[i] = other.arr[i];
    return *this;
}

template <class T>
T   &Array<T>::operator [] (size_t i)
{
    if (i >= this->size())
        throw IndexOutOfBounds();
    else
        return this->arr[i];
}

template <class T>
size_t  Array<T>::size() const
{
    return this->arrSize;
}

template <class T>
void    Array<T>::printArray(std::ostream &out) const
{
    if (this->arrSize == 0)
        return ;
    for (size_t i = 0; i < this->arrSize; i++)
        out << "arr[" << i << "]: " << this->arr[i] << std::endl;
}


#endif