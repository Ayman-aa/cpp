#include "RPN.hpp"

RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(const RPN& other){
    this->numbers = other.numbers;
}

RPN& RPN::operator=(const RPN& other){
    this->numbers = other.numbers;
    return *this;
}

double RPN::strToDouble(std::string test){
    std::stringstream ss;
    double var;
    ss << test;
    ss >> var;
    return var;
}

bool RPN::NameChecker(std::string const &name){
    if (name.find_first_not_of("0123456789") == std::string::npos)
        return true;
    std::cout <<">>|"<< name << "|<<" << std::endl;
    return false;
}


double RPN::rpn(std::stringstream & tokens) {
    std::string token;
    while (tokens >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (numbers.size() < 2) {
                throw std::runtime_error("Error :no left numbers to perform on");
            }
            int b = numbers.top();
            numbers.pop();
            int a = numbers.top();
            numbers.pop();

            if (token == "+")
                numbers.push(a + b);
            if (token == "-")
                numbers.push(a - b);
            if (token == "*")
                numbers.push(a * b);
            if (token == "/")
                numbers.push(a / b);

        } else {
            if (NameChecker(token) && strToDouble(token) < 10)
                    numbers.push(strToDouble(token));
            else
                throw std::runtime_error("Error : bad input");
        }
    }
    if(numbers.size() != 1)
        throw std::runtime_error("Error");
    return numbers.top();
}

const char *RPN::RPNException::what() const throw()
{
    return "Error";
}