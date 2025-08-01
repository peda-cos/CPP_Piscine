/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:15:21 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/01 10:18:42 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX(void) const
{
	return (this->x);
}

Fixed Point::getY(void) const
{
	return (this->y);
}
