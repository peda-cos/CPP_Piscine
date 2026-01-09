#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <exception>

class RPN
{
private:
	std::stack<double> _stack;

	bool isOperator(char c) const;
	bool isDigit(char c) const;
	double applyOperator(double a, double b, char op) const;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	double evaluate(const std::string& expression);

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
