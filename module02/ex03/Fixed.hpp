/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:56:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/02 00:12:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {
	public:
		// Constructor * Destructor
		Fixed( void );
		Fixed( Fixed const& src );
		Fixed( const int nbr );
		Fixed( const float nbr );
		~Fixed( void );

		// Methods

		float	toFloat( void ) const;
		int		toInt( void ) const;

		// Statics

		static Fixed&		min( Fixed& f1, Fixed& f2 );
		static const Fixed&	min( Fixed const& f1, Fixed const& f2 );
		static Fixed&		max( Fixed& f1, Fixed& f2 );
		static const Fixed&	max( Fixed const& f1, Fixed const& f2 );

		// Operator
		Fixed&	operator=(Fixed const& sign);

		bool	operator>(Fixed const& cmp);
		bool	operator<(Fixed const& cmp);
		bool	operator>=(Fixed const& cmp);
		bool	operator<=(Fixed const& cmp);
		bool	operator==(Fixed const& cmp);
		bool	operator!=(Fixed const& cmp);

		Fixed	operator+(Fixed const& src);
		Fixed	operator-(Fixed const& src);
		Fixed	operator*(Fixed const& src);
		Fixed	operator/(Fixed const& src);

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		// Getter * Setter
		int	getRawBits( void ) const;
		static int	getFractionalBits( void );

		void	setRawBits( int const raw );

	private:
		int					_rawBits;
		static const int	_fractionalBits;
};

std::ostream&	operator<<( std::ostream& out, Fixed const& src );

#endif
