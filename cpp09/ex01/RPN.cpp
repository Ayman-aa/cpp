#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const
{
    if(token.empty())
        return false;

    std::string::const_iterator it;
    for(it = token.begin(); it != token.end(); it++)
    {
        if(!std::isdigit(*it))
            return false;
    }
    return true;
}

// convert string to int using std::istringstream which is a stream class to operate on strings
int RPN::strToInt(const std::string &str) const
{
    std::istringstream ss(str);
    int result;
    ss >> result;

    if(ss.fail() || !ss.eof())
        throw RPN::RPNException();
    
    return result;
}

/*
    * 1. pop the last two numbers from the deque
    * 2. perform the operation
    * 3. push the result back to the deque
*/
void RPN::performOperation(const std::string &operation)
{
    if (numbers.size() < 2)
        throw RPN::RPNException();

    int num2 = numbers.back();
    numbers.pop_back();

    int num1 = numbers.back();
    numbers.pop_back();

    int result;

    if (operation == "+")
        result = num1 + num2;
    else if (operation == "-")
        result = num1 - num2;
    else if (operation == "*")
        result = num1 * num2;
    else if (operation == "/")
    {
        if (num2 == 0)
            throw RPN::RPNException();
        result = num1 / num2;
    }
    else
        throw RPN::RPNException();
    
    numbers.push_back(result);
}

/*
    * 1. read the expression token by token
    * 2. if the token is a number, push it to the deque
    * 3. if the token is an operator, perform the operation
    * 4. if the token is neither a number nor an operator, throw an exception
    * 5. if the deque has more than one number left, throw an exception
    * 6. return the result
*/
int RPN::calculate(const std::string &expression)
{
    std::istringstream ss(expression);
    std::string token;

    numbers.clear();

    while (ss >> token)
    {
        if (isNumber(token))
        {
            int number = strToInt(token);
            if (number >= 10)
                throw RPN::RPNException();

            numbers.push_back(number);
        }
        else if (isOperator(token))
            performOperation(token);
        else
            throw RPN::RPNException();
    }

    if (numbers.size() != 1)
        throw RPN::RPNException();
    
    return numbers.front();
}

const char *RPN::RPNException::what() const throw()
{
    return "Error";
}