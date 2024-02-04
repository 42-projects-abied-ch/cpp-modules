#ifndef ITER_HPP
# define ITER_HPP

# pragma once

# include <iostream>

template <typename T>
void    iter(T *arr, size_t arrLen, void(*f)(const T &thing))
{
    for (size_t i = 0; i < arrLen; i++)
        f(arr[i]);
}

#endif