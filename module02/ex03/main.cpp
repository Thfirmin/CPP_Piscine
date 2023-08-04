/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:23:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:09:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	putSquare( int bin );

int	main( void )
{
	Point	a(0, 0);
	Point	b(2, 2);
	Point	c(4, 0);
	float		maxX;
	float		maxY;
	float		minX;
	float		minY;
	float		step = 0.25;

	maxX = Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX())).toFloat();
	maxY = Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY())).toFloat();
	minX = Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX())).toFloat();
	minY = Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY())).toFloat();

	Point::setDebug( false );

	Fixed	y(maxY);
	while (y.toFloat() >= minY)
	{
		Fixed	x(minX);
		while (x.toFloat() <= maxX)
		{
			Point	p(x.toFloat(), y.toFloat());
			putSquare(bsp(a, b, c, p));
			x = (x + step);
		}
		std::cout << std::endl;
		y = (y - step);
	}

	return 0;
}

void	putSquare( int bin )
{
	if (bin == 1)
		std::cout << "\e[32m";
	else if (bin == -1)
		std::cout << "\e[33m";
	else
		std::cout << "\e[31m";
	std::cout << "■" << "\e[0m";
	return ;
}
