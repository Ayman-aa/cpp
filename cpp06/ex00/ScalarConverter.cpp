#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <cstring>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    if (isSpecialValue(literal)) {
        handleSpecialValue(literal);
        return;
    }

    std::string parsableString = literal;
    bool isFloat = false;
    
    // Check if it's a float literal (ends with 'f' or 'F')
    if (literal.length() > 1) {
        char lastChar = literal[literal.length() - 1];
        if (lastChar == 'f' || lastChar == 'F') {
            parsableString = literal.substr(0, literal.length() - 1);
            isFloat = true;
        }
    }

    // Try to parse as double
    char* endPtr;
    double value = strtod(parsableString.c_str(), &endPtr);

    // Check if the entire string was parsed
    if (*endPtr != '\0') {
        // If it's a single character, treat it as char
        if (literal.length() == 1) {
            value = static_cast<double>(literal[0]);
        } else {
            std::cout << "Error: Invalid input" << std::endl;
            return;
        }
    }

    printConversions(value, isFloat);
}

bool ScalarConverter::isSpecialValue(const std::string& literal) {
    return literal == "nan" || literal == "nanf" || 
           literal == "inf" || literal == "inff" || 
           literal == "+inf" || literal == "+inff" || 
           literal == "-inf" || literal == "-inff";
}

void ScalarConverter::handleSpecialValue(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

void ScalarConverter::printConversions(double value, bool isFloat)
{
    printChar(value);
    printInt(value);
    printFloat(value, isFloat);
    printDouble(value, isFloat);
}

void ScalarConverter::printChar(double value) {
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value)) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value, bool isFloat) {
    std::cout << "float: ";
    if (value != value) { 
        std::cout << "nanf" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "+inff" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "-inff" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(isFloat ? 7 : 6)
                  << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, bool isFloat) {
    std::cout << "double: ";
    if (value != value) { // Check for NaN
        std::cout << "nan" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "+inf" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "-inf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(isFloat ? 7 : 15)
                  << value << std::endl;
    }
}