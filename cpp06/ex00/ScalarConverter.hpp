#ifndef SCALARCONVERTER
#define SCALARCONVERTER

# include <iostream>
# include <iomanip>
# include <cstring>
# include <limits>
# include <cstdlib>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
	
	public:
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		static void convert(const std::string &literal);
		static bool isSpecialValue(const std::string &literal);
		static void handleSpecialValue(const std::string &literal);
		static void printConversions(double value, bool isFloat);
		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value, bool isFloat);
		static void printDouble(double value, bool isFloat);
};

#endif
