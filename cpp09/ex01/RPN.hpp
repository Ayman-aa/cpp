#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stack>
#include <cstdlib>
#include <list>

class RPN
{
    private:
        std::stack<int, std::list<int> > numbers;
        bool isOperator(const std::string &token) const;
        bool isNumber(const std::string &token) const;
        int strToInt(const std::string &str) const;
        void performOperation(const std::string &operation);
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        int calculate(const std::string &expression);
    
    class RPNException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };
};
#endif