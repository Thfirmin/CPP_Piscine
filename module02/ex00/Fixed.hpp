/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:24:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/29 10:08:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	public:
		// Constructor * Destructor
		Fixed( void );
		Fixed( Fixed const& src );
		~Fixed( void );

		// Operators
		Fixed&	operator=(Fixed const& operand);

		// Methods

		// Getter * Setter
		int	getRawBits( void ) const;
		static int	getFractionalBits( void );

		void	setRawBits( int const raw );

	private:
		int					_rawBits;
		static const int	_fractionalBits;
};

#endif
