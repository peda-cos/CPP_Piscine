#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <limits>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	enum LiteralType {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO_LITERAL,
		INVALID
	};

	static LiteralType detectType(const std::string& literal);
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isPseudoLiteral(const std::string& literal);

	static void printChar(double value, bool impossible);
	static void printInt(double value, bool impossible);
	static void printFloat(double value, bool isPseudo, const std::string& literal);
	static void printDouble(double value, bool isPseudo, const std::string& literal);

public:
	static void convert(const std::string& literal);
};

#endif
