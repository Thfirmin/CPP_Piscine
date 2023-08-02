/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:56:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/01 18:05:46 by thfirmin         ###   ########.fr       */
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

		// Operator
		Fixed&	operator=(Fixed const& sign);

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
