/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:04:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 12:06:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor * Destructor

Fixed::Fixed( void ) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int nbr ) : _rawBits(nbr << getFractionalBits()) {
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const float nbr ) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = static_cast<int>(roundf(nbr * (1 << getFractionalBits())));
	return ;
}

Fixed::Fixed( Fixed const& src ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

// Methods

float	Fixed::toFloat( void ) const {
	return ((float)(this->getRawBits()) / (float)(1 << getFractionalBits()));
}

int	Fixed::toInt( void ) const {
	return (this->getRawBits() >> Fixed::getFractionalBits());
}

// Operator

Fixed&	Fixed::operator=(Fixed const& sign) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = sign.getRawBits();
	return *this;
}

std::ostream&	operator<<( std::ostream& out, Fixed const& src ) {
	out << src.toFloat();
	return out;
}

// Getter * Setter

int	Fixed::getRawBits( void ) const {
	return this->_rawBits;
}

int	Fixed::getFractionalBits( void ) {
	return Fixed::_fractionalBits;
}

void	Fixed::setRawBits( int const raw ) {
	this->_rawBits = raw;
	return ;
}

const int	Fixed::_fractionalBits = 8;
