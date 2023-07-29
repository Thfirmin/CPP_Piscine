/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:25:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/29 10:14:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const& src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const& operand) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = operand.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

int	Fixed::getFractionalBits( void ) {
	std::cout << "getFractionalBits member function called" << std::endl;
	return Fixed::_fractionalBits;
}

void	Fixed::setRawBits( int rawBits ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = rawBits;
	return ;
}
const int	Fixed::_fractionalBits = 8;
