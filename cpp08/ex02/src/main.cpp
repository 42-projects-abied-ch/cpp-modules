#include "../inc/MutantStack.hpp"
#include <iostream>

const char  *IteratorFailure::what() const throw()
{
    return "Error: Iterator test failed";
};

void testIterator()
{
    MutantStack<int> stack;

    for (int i = 1; i <= 5; ++i)
        stack.push(i);

    int expectedValue = 1;
    for (MutantStack <int>::iterator it = stack.begin(); it != stack.end(); it++)
    {
        if (*it != expectedValue)
            throw IteratorFailure();
        std::cout << "Passed!" << std::endl;
        std::cout << "Iterator Value: [" << *it << "] - Expected Value: [" << expectedValue << "]\n" << std::endl;
        expectedValue++;
    }

    stack.pop();

    expectedValue = 1;

    for (MutantStack <int>::iterator it = stack.begin(); it != stack.end(); it++)
    {
        if (*it != expectedValue) 
            throw IteratorFailure();
        std::cout << "Passed!" << std::endl;
        std::cout << "Iterator Value: [" << *it << "] - Expected Value: [" << expectedValue << "]\n" << std::endl;
        expectedValue++;
    }

    MutantStack <int> emptyStack;
    stack = emptyStack;
    if (stack.begin() != stack.end())
        throw IteratorFailure();
}

int main()
{
    try
    {
        testIterator();
        std::cout << "All tests passed!\n";
    }
    catch (const IteratorFailure& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}