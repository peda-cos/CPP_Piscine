/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:30:00 by peda-cos          #+#    #+#             */
/*   Updated: 2025/10/05 23:50:56 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Orthodox Canonical Form (private - non-instantiable class)
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// Type detection helpers
bool ScalarConverter::isCharLiteral(const std::string &str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isPseudoLiteral(const std::string &str) {
    return (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" ||
	    str == "+inff" || str == "-inff" || str == "inf" || str == "inff");
}

bool ScalarConverter::isIntLiteral(const std::string &str) {
    if (str.empty())
	return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
	i++;

    if (i >= str.length())
	return false;

    while (i < str.length()) {
	if (!isdigit(str[i]))
	    return false;
	i++;
    }
    return true;
}

bool ScalarConverter::isFloatLiteral(const std::string &str) {
    if (str.empty() || str[str.length() - 1] != 'f')
	return false;

    std::string numPart = str.substr(0, str.length() - 1);
    if (numPart.empty())
	return false;

    size_t i = 0;
    if (numPart[i] == '+' || numPart[i] == '-')
	i++;

    bool hasDot = false;
    bool hasDigit = false;

    while (i < numPart.length()) {
	if (numPart[i] == '.') {
	    if (hasDot)
		return false;
	    hasDot = true;
	} else if (isdigit(numPart[i]))
	    hasDigit = true;
	else
	    return false;
	i++;
    }
    return hasDigit && hasDot;
}

bool ScalarConverter::isDoubleLiteral(const std::string &str) {
    if (str.empty())
	return false;

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
	i++;

    bool hasDot = false;
    bool hasDigit = false;

    while (i < str.length()) {
	if (str[i] == '.') {
	    if (hasDot)
		return false;
	    hasDot = true;
	} else if (isdigit(str[i]))
	    hasDigit = true;
	else
	    return false;
	i++;
    }
    return hasDigit && hasDot;
}

// Display helpers
void ScalarConverter::displayChar(double value, bool impossible) {
    std::cout << "char: ";
    if (impossible || std::isnan(value) || std::isinf(value))
	std::cout << "impossible";
    else if (value < 0 || value > 127)
	std::cout << "impossible";
    else if (value < 32 || value == 127)
	std::cout << "Non displayable";
    else
	std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

void ScalarConverter::displayInt(double value, bool impossible) {
    std::cout << "int: ";
    if (impossible || std::isnan(value) || std::isinf(value))
	std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() ||
	     value > std::numeric_limits<int>::max())
	std::cout << "impossible";
    else
	std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

void ScalarConverter::displayFloat(double value, bool impossible) {
    std::cout << "float: ";
    if (impossible)
	std::cout << "impossible";
    else {
	float f = static_cast<float>(value);
	if (std::isnan(f))
	    std::cout << "nanf";
	else if (std::isinf(f))
	    std::cout << (f > 0 ? "+inff" : "-inff");
	else {
	    // Show at least one decimal place, but more if needed
	    if (f == static_cast<int>(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	    else
		std::cout << f << "f";
	}
    }
    std::cout << std::endl;
}

void ScalarConverter::displayDouble(double value, bool impossible) {
    std::cout << "double: ";
    if (impossible)
	std::cout << "impossible";
    else {
	if (std::isnan(value))
	    std::cout << "nan";
	else if (std::isinf(value))
	    std::cout << (value > 0 ? "+inf" : "-inf");
	else {
	    // Show at least one decimal place, but more if needed
	    if (value == static_cast<int>(value))
		std::cout << std::fixed << std::setprecision(1) << value;
	    else
		std::cout << value;
	}
    }
    std::cout << std::endl;
}

// Conversion from detected types
void ScalarConverter::convertFromChar(char c) {
    double value = static_cast<double>(c);
    displayChar(value, false);
    displayInt(value, false);
    displayFloat(value, false);
    displayDouble(value, false);
}

void ScalarConverter::convertFromInt(long value) {
    bool intImpossible = (value < std::numeric_limits<int>::min() ||
			  value > std::numeric_limits<int>::max());

    double dValue = static_cast<double>(value);
    displayChar(dValue, false);
    displayInt(dValue, intImpossible);
    displayFloat(dValue, false);
    displayDouble(dValue, false);
}

void ScalarConverter::convertFromFloat(float value) {
    double dValue = static_cast<double>(value);
    displayChar(dValue, false);
    displayInt(dValue, false);
    displayFloat(dValue, false);
    displayDouble(dValue, false);
}

void ScalarConverter::convertFromDouble(double value) {
    displayChar(value, false);
    displayInt(value, false);
    displayFloat(value, false);
    displayDouble(value, false);
}

void ScalarConverter::convertPseudoLiteral(const std::string &str) {
    double value;

    if (str == "nan" || str == "nanf")
	value = std::numeric_limits<double>::quiet_NaN();
    else if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	value = std::numeric_limits<double>::infinity();
    else if (str == "-inf" || str == "-inff")
	value = -std::numeric_limits<double>::infinity();
    else
	value = 0;

    displayChar(value, false);
    displayInt(value, false);
    displayFloat(value, false);
    displayDouble(value, false);
}

// Main conversion method
void ScalarConverter::convert(const std::string &literal) {
    if (literal.empty()) {
	std::cout << "Error: empty literal" << std::endl;
	return;
    }

    // Check for pseudo-literals first
    if (isPseudoLiteral(literal)) {
	convertPseudoLiteral(literal);
	return;
    }

    // Check for char literal
    if (isCharLiteral(literal)) {
	convertFromChar(literal[1]);
	return;
    }

    // Check for float literal
    if (isFloatLiteral(literal)) {
	char *endPtr;
	errno = 0;
	double value = strtod(literal.c_str(), &endPtr);
	if (errno == ERANGE) {
	    std::cout << "Error: overflow detected" << std::endl;
	    return;
	}
	convertFromFloat(static_cast<float>(value));
	return;
    }

    // Check for double literal
    if (isDoubleLiteral(literal)) {
	char *endPtr;
	errno = 0;
	double value = strtod(literal.c_str(), &endPtr);
	if (errno == ERANGE) {
	    std::cout << "Error: overflow detected" << std::endl;
	    return;
	}
	convertFromDouble(value);
	return;
    }

    // Check for int literal
    if (isIntLiteral(literal)) {
	char *endPtr;
	errno = 0;
	long value = strtol(literal.c_str(), &endPtr, 10);
	if (errno == ERANGE) {
	    std::cout << "Error: overflow detected" << std::endl;
	    return;
	}
	convertFromInt(value);
	return;
    }

    // If nothing matches, it's an invalid literal
    std::cout << "Error: invalid literal format" << std::endl;
}
