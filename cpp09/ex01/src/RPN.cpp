#include "../inc/RPN.hpp"
#include <cctype>
#include <cstdlib>

bool    isOperator(char c)
{
    return c == '*' || c == '/' || c == '-' || c == '+';
}
int     RPN(std::string tokens)
{
    std::stack<int> stk;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == ' ')
            continue ;
        else if (isOperator(tokens[i]) == true)
        {
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
        else if (std::isdigit(tokens[i]) == true)
            stk.push(tokens[i] - '0');
        else
        {
            std::cerr << "Error" << std::endl;
        }
    }
    return stk.top();
}

