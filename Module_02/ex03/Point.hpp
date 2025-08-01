/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:15:23 by peda-cos          #+#    #+#             */
/*   Updated: 2025/08/01 10:18:11 by peda-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	Fixed const x;
	Fixed const y;

  public:
	Point();
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	Point(const float x_val, const float y_val);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
