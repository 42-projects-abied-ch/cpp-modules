#include "../inc/RPN.hpp"

const char	*InvalidInput::what() const throw()
{
	return "invalid input (./RPN \". . . .\")";
}

const char  *InvalidCharacter::what() const throw()
{
    return "invalid character";
}

const char  *InvalidExpression::what() const throw()
{
    return "invalid expression";
}

const char  *MultipleDigits::what() const throw()
{
    return "multiple digits number found";
}

const char	*IntegerOverflow::what() const throw()
{
    return "notation resulted in integer overflow";
}

const char	*DivisionByZero::what() const throw()
{
	return "division by zero";	
}

bool    isOperator(char c)
{
    return c == '*' || c == '/' || c == '-' || c == '+';
}

void checkForOverflow(int num1, int num2, char operation)
{
    switch (operation)
    {
        case '+':
            if ((num2 > 0 && num1 > INT_MAX - num2) || (num2 < 0 && num1 < INT_MIN - num2))
                throw IntegerOverflow();
            break;
        case '-':
            if ((num2 > 0 && num1 < INT_MIN + num2) || (num2 < 0 && num1 > INT_MAX + num2))
                throw IntegerOverflow();
            break;
        case '*':
            if (num1 != 0 && (num2 > INT_MAX / num1 || num2 < INT_MIN / num1))
                throw IntegerOverflow();
            break;
        case '/':
			if (num2 == 0)
				throw DivisionByZero();
            if (num1 == INT_MIN && num2 == -1)
                throw IntegerOverflow();
            break;
    }
}

void performOperation(std::stack<int>& stk, char operation)
{
    if (stk.size() < 2)
        throw InvalidExpression();
    int num2 = stk.top();
    stk.pop();
    int num1 = stk.top();
    stk.pop();
    checkForOverflow(num1, num2, operation);
    switch (operation)
    {
        case '+':
            stk.push(num1 + num2);
            break;
        case '-':
            stk.push(num1 - num2);
            break;
        case '*':
            stk.push(num1 * num2);
            break;
        case '/':
            stk.push(num1 / num2);
            break;
    }
}

void checkTokens(std::string tokens)
{
    int numCount = 0;
    int opCount = 0;
    int n = tokens.size();

    for (int i = 0; i < n; i++)
    {
        if (std::isdigit(tokens[i]) == true && std::isdigit(tokens[i + 1]) == true)
            throw MultipleDigits();
        if (std::isdigit(tokens[i]) != false)
            numCount++;
        else if (isOperator(tokens[i]) == true)
            opCount++;
        else if (tokens[i] != ' ')
            throw InvalidCharacter();
    }
    if (numCount - opCount != 1)
        throw InvalidExpression();
}

void RPN(std::string tokens)
{
    std::stack<int> stk;
    int n = tokens.size();
    checkTokens(tokens);

    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == ' ')
            continue ;
        else if (isOperator(tokens[i]) == true)
            performOperation(stk, tokens[i]);
        else
            stk.push(tokens[i] - '0');
    }
    std::cout << stk.top() << std::endl;
}