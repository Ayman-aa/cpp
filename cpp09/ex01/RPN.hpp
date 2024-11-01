#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


class RPN {
    private:
        stack<double> numbers;
    public:
        RPN();
        ~RPN();
        RPN & operator=(RPN const & other);
        RPN(const RPN & other);
        double  rpn(std::stringstream & tokens);
        bool NameChecker(std::string const &name);
        double strToDouble(std::string test);

        class RPNException: public std::exception {
            public:
                virtual const char* what() const throw() ;
        };
};
#endif