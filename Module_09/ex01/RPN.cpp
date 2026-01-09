#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c) const
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isDigit(char c) const
{
	return c >= '0' && c <= '9';
}

double RPN::applyOperator(double a, double b, char op) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
			{
				throw DivisionByZeroException();
			}
			return a / b;
		default:
			throw InvalidExpressionException();
	}
}

double RPN::evaluate(const std::string& expression)
{
	while (!_stack.empty())
	{
		_stack.pop();
	}

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isDigit(token[0]))
		{
			_stack.push(static_cast<double>(token[0] - '0'));
		}
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
			{
				throw InvalidExpressionException();
			}
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			_stack.push(applyOperator(a, b, token[0]));
		}
		else
		{
			throw InvalidExpressionException();
		}
	}

	if (_stack.size() != 1)
	{
		throw InvalidExpressionException();
	}

	return _stack.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error";
}
