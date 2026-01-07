#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
	return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
	return literal == "nan" || literal == "nanf" ||
		   literal == "+inf" || literal == "-inf" ||
		   literal == "+inff" || literal == "-inff" ||
		   literal == "inf" || literal == "inff";
}

bool ScalarConverter::isInt(const std::string& literal) {
	if (literal.empty())
		return false;
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i >= literal.length())
		return false;
	for (; i < literal.length(); i++) {
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	std::string withoutF = literal.substr(0, literal.length() - 1);
	if (withoutF.empty())
		return false;
	size_t i = 0;
	if (withoutF[i] == '+' || withoutF[i] == '-')
		i++;
	if (i >= withoutF.length())
		return false;
	bool hasDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;
	for (; i < withoutF.length(); i++) {
		if (withoutF[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (std::isdigit(withoutF[i])) {
			if (hasDot)
				hasDigitAfterDot = true;
			else
				hasDigitBeforeDot = true;
		} else {
			return false;
		}
	}
	return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

bool ScalarConverter::isDouble(const std::string& literal) {
	if (literal.empty())
		return false;
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i >= literal.length())
		return false;
	bool hasDot = false;
	bool hasDigitBeforeDot = false;
	bool hasDigitAfterDot = false;
	for (; i < literal.length(); i++) {
		if (literal[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (std::isdigit(literal[i])) {
			if (hasDot)
				hasDigitAfterDot = true;
			else
				hasDigitBeforeDot = true;
		} else {
			return false;
		}
	}
	return hasDot && hasDigitBeforeDot && hasDigitAfterDot;
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal) {
	if (isChar(literal))
		return CHAR;
	if (isPseudoLiteral(literal))
		return PSEUDO_LITERAL;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	if (isInt(literal))
		return INT;
	return INVALID;
}

void ScalarConverter::printChar(double value, bool impossible) {
	std::cout << "char: ";
	if (impossible || std::isnan(value) || std::isinf(value) ||
		value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
	} else if (value < 32 || value > 126) {
		std::cout << "Non displayable" << std::endl;
	} else {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}
}

void ScalarConverter::printInt(double value, bool impossible) {
	std::cout << "int: ";
	if (impossible || std::isnan(value) || std::isinf(value) ||
		value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)) {
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::printFloat(double value, bool isPseudo, const std::string& literal) {
	std::cout << "float: ";
	if (isPseudo) {
		if (literal == "nan" || literal == "nanf")
			std::cout << "nanf" << std::endl;
		else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	} else {
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value, bool isPseudo, const std::string& literal) {
	std::cout << "double: ";
	if (isPseudo) {
		if (literal == "nan" || literal == "nanf")
			std::cout << "nan" << std::endl;
		else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	LiteralType type = detectType(literal);
	double value = 0;
	bool impossible = false;
	bool isPseudo = false;

	switch (type) {
		case CHAR:
			value = static_cast<double>(literal[1]);
			break;
		case INT: {
			long lval = std::strtol(literal.c_str(), NULL, 10);
			if (lval < INT_MIN || lval > INT_MAX)
				impossible = true;
			value = static_cast<double>(lval);
			break;
		}
		case FLOAT: {
			std::string withoutF = literal.substr(0, literal.length() - 1);
			value = std::strtod(withoutF.c_str(), NULL);
			break;
		}
		case DOUBLE:
			value = std::strtod(literal.c_str(), NULL);
			break;
		case PSEUDO_LITERAL:
			isPseudo = true;
			if (literal == "nan" || literal == "nanf")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
				value = std::numeric_limits<double>::infinity();
			else
				value = -std::numeric_limits<double>::infinity();
			break;
		case INVALID:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
	}

	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value, isPseudo, literal);
	printDouble(value, isPseudo, literal);
}
