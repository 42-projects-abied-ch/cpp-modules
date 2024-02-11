#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# pragma once

# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>
# include <stack>
# include <list>
# include <sstream>

class IteratorFailure : public std::exception
{
    public:
    
       virtual const char  *what() const throw();
};

template <typename T>
class MutantStack : public std::stack <T>
{
    public:
    
        MutantStack <T>();
        MutantStack <T>(const MutantStack<T> &other);
        ~MutantStack <T>();

        MutantStack <T>  &operator = (const MutantStack<T> &other);

        typedef typename std::stack <int>::container_type::iterator iterator;

        iterator    begin();
        iterator    end();
};

template <typename T>
MutantStack<T>::MutantStack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
    *this = other;
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
MutantStack<T>  &MutantStack <T>::operator = (const MutantStack<T> &other)
{
    if (this == &other)
        return *this;
    std::stack <T>::operator = (other);
    return *this;
}

template <typename T>
typename MutantStack <T>::iterator   MutantStack<T>::begin()
{
    return std::stack <T>::c.begin();
}

template <typename T>
typename MutantStack <T>::iterator  MutantStack<T>::end()
{
    return std::stack <T>::c.end();
}

#endif