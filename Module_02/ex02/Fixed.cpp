/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:42:30 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/30 09:55:05 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const int int_val) : _fixedPointValue(int_val << _fractionalBits)
{
}

Fixed::Fixed(const float float_val) : _fixedPointValue(roundf(float_val
		* (1 << _fractionalBits)))
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long long temp = (long long)this->_fixedPointValue
		* (long long)other._fixedPointValue;
	result.setRawBits((int)(temp >> _fractionalBits));
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._fixedPointValue == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed());
	}
	Fixed result;
	long long temp = ((long long)this->_fixedPointValue << _fractionalBits)
		/ other._fixedPointValue;
	result.setRawBits((int)temp);
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_fixedPointValue += 1;
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
