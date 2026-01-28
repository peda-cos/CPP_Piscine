#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <exception>

class RPN
{
private:
	std::stack<double> _operandStack;

	bool isOperatorToken(char token) const;
	bool isSingleDigit(char token) const;
	double evaluateBinaryOperation(double leftOperand, double rightOperand, char op) const;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	double evaluateExpression(const std::string& expression);

	class InvalidExpressionException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class DivisionByZeroException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif
