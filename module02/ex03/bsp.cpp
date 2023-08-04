/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:11:39 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:10:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	triangleArea( Point const& a, Point const& b, Point const& c, bool debug );

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	bool	debug = Point::getDebug();

	if (debug) {
		std::cout << "A(" << a.getX() << "," << a.getY() << ") | ";
		std::cout << "B(" << b.getX() << "," << b.getY() << ") | ";
		std::cout << "C(" << c.getX() << "," << c.getY() << ") | ";
		std::cout << "P(" << point.getX() << "," << point.getY() << ")" << std::endl;
		std::cout << "______________________________________________" << std::endl;
		std::cout << "Area ABC: {" << std::endl;
	}

	Fixed	ABC(triangleArea(a, b, c, debug));

	if (debug) {
		std::cout << "}" << std::endl;
		std::cout << "Area PBC: {" << std::endl;
	}

	Fixed	PBC(triangleArea(point, b, c, debug));

	if (debug) {
		std::cout << "}" << std::endl;
		std::cout << "Area APC: {" << std::endl;
	}

	Fixed	APC(triangleArea(a, point, c, debug));

	if (debug) {
		std::cout << "}" << std::endl;
		std::cout << "Area ABP: {" << std::endl;
	}

	Fixed	ABP(triangleArea(a, b, point, debug));

	if (debug) {
		std::cout << "}" << std::endl;
		std::cout << PBC << " + " << APC << " + " << ABP << " => " << (PBC + APC + ABP) << " == " << ABC << ": " << (ABC == (PBC + APC + ABP)) << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
	}

	if (!PBC.toFloat() || !APC.toFloat() || !ABP.toFloat())
		return false;
	return (ABC == (PBC + APC + ABP));
}

static float	triangleArea( Point const& a, Point const& b, Point const& c, bool debug )
{
	Fixed	m1(a.getX() * (b.getY() - c.getY()));
	Fixed	m2(b.getX() * (c.getY() - a.getY()));
	Fixed	m3(c.getX() * (a.getY() - b.getY()));

	if (debug) {
		std::cout << "\tm1: (" << a.getX() << " * (" << b.getY() << " - " << c.getY() << ")) => " << a.getX() << " * " << (b.getY() - c.getY()) << " = " << m1 << std::endl;
		std::cout << "\tm2: (" << b.getX() << " * (" << c.getY() << " - " << a.getY() << ")) => " << b.getX() << " * " << (c.getY() - a.getY()) << " = " << m2 << std::endl;
		std::cout << "\tm3: (" << c.getX() << " * (" << a.getY() << " - " << b.getY() << ")) => " << c.getX() << " * " << (a.getY() - b.getY()) << " = " << m3 << std::endl;
		std::cout << "\t|" << m1 << " + " << m2 << " + " << m3 << "| = " << fabs((m1 + m2 + m3).toFloat()) << " / 2 = " << (fabs((m1 + m2 + m3).toFloat()) * 0.5) << std::endl;
	}

	return fabs((m1 + m2 + m3).toFloat()) * 0.5;
}
