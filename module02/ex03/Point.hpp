/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:08:13 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:05:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	public:
		Point( void );
		Point( float const _x, float const _y );
		Point( Point const& src );
		~Point( void );
	
		Point&	operator=( Point const& sign );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

		static bool	getDebug( void );
		static void	setDebug( bool debug );

	private:
		const Fixed	x;
		const Fixed	y;
		static bool	_debug;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point );

#endif
