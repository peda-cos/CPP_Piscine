/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:15:28 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/01 10:19:20 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calculateArea(Point const &a, Point const &b, Point const &c)
{
	Fixed	area;

	area = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY()
					- a.getY())) + (c.getX() * (a.getY() - b.getY())));
	if (area < 0)
		area = area * Fixed(-1);
	return (area / Fixed(2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangleArea;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;
	Fixed	sumAreas;

	triangleArea = calculateArea(a, b, c);
	if (triangleArea == 0)
		return (false);
	area1 = calculateArea(point, b, c);
	area2 = calculateArea(a, point, c);
	area3 = calculateArea(a, b, point);
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	sumAreas = area1 + area2 + area3;
	return (sumAreas == triangleArea);
}
