/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:24:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/18 00:38:59 by thfirmin         ###   ########.fr       */
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

		// Operator
		Fixed&	operator=(Fixed const& sign);

		// Getter * Setter
		int			getRawBits( void ) const;
		static int	getFractionalBits( void );

		void		setRawBits( int const raw );

	private:
		int					_rawBits;
		static const int	_fractionalBits;
};

#endif
