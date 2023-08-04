/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:09:33 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:06:01 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Variables

bool	Point::_debug = 0;

// Constructor * Destructor
Point::Point( void ) : x(0), y(0) {
	return ;
}

Point::Point( float const _x, float const _y ) : x(_x), y(_y) {
	return ;
}

Point::Point( Point const& src ) : x(src.x), y(src.y) {
	return ;
}

Point::~Point( void ) {
	return ;
}

// Getter * Setter
Fixed	Point::getX( void ) const {
	return this->x;
}

Fixed	Point::getY( void ) const {
	return this->y;
}

bool	Point::getDebug( void ) {
	return Point::_debug;
}

void	Point::setDebug( bool debug ) {
	Point::_debug = debug;
	return ;
}

// Operator

Point&	Point::operator=( Point const& sign ) {
	(void) sign;
	return *this;
}
