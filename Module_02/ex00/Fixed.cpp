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
