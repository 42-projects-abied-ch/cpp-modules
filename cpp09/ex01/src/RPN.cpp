#include "../inc/RPN.hpp"
#include <cctype>
#include <cstdlib>

const char  *InvalidCharacter::what() const throw()
{
    return "Invalid Character";
}

const char  *InvalidExpression::what() const throw()
{
    return "Invalid Expression";
}

const char  *MultipleDigits::what() const throw()
{
    return "Multiple Digits Number Found";
}

void    checkTokens(std::string tokens)
{
    int numCount = 0;
    int opCount = 0;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        if (std::isdigit(tokens[i]) == true && std::isdigit(tokens[i + 1]) == true)
            throw MultipleDigits();
        if (std::isdigit(tokens[i]) == true)
            numCount++;
        else if (isOperator(tokens[i]) == true)
            opCount++;
        else if (tokens[i] != ' ')
            throw InvalidCharacter();
    }
    if (numCount - opCount != 1)
        throw InvalidExpression();
}

bool    isOperator(char c)
{
    return c == '*' || c == '/' || c == '-' || c == '+';
}
void     RPN(std::string tokens)
{
    std::stack<int> stk;
    int n = tokens.size();
    checkTokens(tokens);

    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == ' ')
            continue ;
        else if (isOperator(tokens[i]) == true)
        {
            if (stk.size() < 2)
                throw InvalidExpression();
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            if (tokens[i] == '+')
                stk.push(num1 + num2);
            else if (tokens[i] == '-')
                stk.push(num1 - num2);
            else if (tokens[i] == '*')
                stk.push(num1 * num2);
            else if (tokens[i] == '/')
                stk.push(num1 / num2);
        } 
        else
            stk.push(tokens[i] - '0');
    }
    std::cout << stk.top() << std::endl;
}

