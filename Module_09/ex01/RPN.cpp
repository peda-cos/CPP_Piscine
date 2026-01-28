#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN()
{
}

RPN::RPN(const RPN& other) : _operandStack(other._operandStack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_operandStack = other._operandStack;
	}
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperatorToken(char token) const
{
	return token == '+' || token == '-' || token == '*' || token == '/';
}

bool RPN::isSingleDigit(char token) const
{
	return token >= '0' && token <= '9';
}

double RPN::evaluateBinaryOperation(double leftOperand, double rightOperand, char op) const
{
	switch (op)
	{
		case '+':
			return leftOperand + rightOperand;
		case '-':
			return leftOperand - rightOperand;
		case '*':
			return leftOperand * rightOperand;
		case '/':
			if (rightOperand == 0)
			{
				throw DivisionByZeroException();
			}
			return leftOperand / rightOperand;
		default:
			throw InvalidExpressionException();
	}
}

double RPN::evaluateExpression(const std::string& expression)
{
	while (!_operandStack.empty())
	{
		_operandStack.pop();
	}

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isSingleDigit(token[0]))
		{
			_operandStack.push(static_cast<double>(token[0] - '0'));
		}
		else if (token.length() == 1 && isOperatorToken(token[0]))
		{
			if (_operandStack.size() < 2)
			{
				throw InvalidExpressionException();
			}
			double rightOperand = _operandStack.top();
			_operandStack.pop();
			double leftOperand = _operandStack.top();
			_operandStack.pop();
			_operandStack.push(evaluateBinaryOperation(leftOperand, rightOperand, token[0]));
		}
		else
		{
			throw InvalidExpressionException();
		}
	}

	if (_operandStack.size() != 1)
	{
		throw InvalidExpressionException();
	}

	return _operandStack.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error";
}
