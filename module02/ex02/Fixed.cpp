/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:04:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 12:06:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor * Destructor

Fixed::Fixed( void ) : _rawBits(0) {
//	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const int nbr ) : _rawBits(nbr << getFractionalBits()) {
//	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const float nbr ) {
//	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = static_cast<int>(roundf(nbr * (1 << getFractionalBits())));
	return ;
}

Fixed::Fixed( Fixed const& src ) {
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void ) {
//	std::cout << "Destructor called" << std::endl;
	return ;
}

// Methods

float	Fixed::toFloat( void ) const {
	return ((float)(this->getRawBits()) / (float)(1 << getFractionalBits()));
}

int	Fixed::toInt( void ) const {
	return (this->getRawBits() >> Fixed::getFractionalBits());
}

// Statics

Fixed&			Fixed::min( Fixed& f1, Fixed& f2 ) {
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed&	Fixed::min( Fixed const& f1, Fixed const& f2 ) {
	if (f1.getRawBits() < f2.getRawBits())
		return f1;
	return f2;
}

Fixed&			Fixed::max( Fixed& f1, Fixed& f2 ) {
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed&	Fixed::max( Fixed const& f1, Fixed const& f2 ) {
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	return f2;
}

// Operator

Fixed&	Fixed::operator=(Fixed const& sign) {
//	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawBits = sign.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const& cmp) {
	return this->_rawBits > cmp.getRawBits();
}

bool	Fixed::operator<(Fixed const& cmp) {
	return this->_rawBits < cmp.getRawBits();
}

bool	Fixed::operator>=(Fixed const& cmp) {
	return this->_rawBits >= cmp.getRawBits();
}

bool	Fixed::operator<=(Fixed const& cmp) {
	return this->_rawBits <= cmp.getRawBits();
}

bool	Fixed::operator==(Fixed const& cmp) {
	return this->_rawBits == cmp.getRawBits();
}

bool	Fixed::operator!=(Fixed const& cmp) {
	return this->_rawBits != cmp.getRawBits();
}

Fixed	Fixed::operator+(Fixed const& src) {
	return Fixed( this->toFloat() + src.toFloat() );
}

Fixed	Fixed::operator-(Fixed const& src) {
	return Fixed( this->toFloat() - src.toFloat() );
}

Fixed	Fixed::operator*(Fixed const& src) {
	return Fixed( this->toFloat() * src.toFloat() );
}

Fixed	Fixed::operator/(Fixed const& src) {
	return Fixed( this->toFloat() / src.toFloat() );
}

Fixed&	Fixed::operator++( void ) {
	this->_rawBits ++;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed	tmp = *this;
	this->_rawBits ++;
	return tmp;
}

Fixed&	Fixed::operator--( void ) {
	this->_rawBits --;
	return *this;
}

Fixed	Fixed::operator--( int ) {
	Fixed	tmp = *this;
	this->_rawBits --;
	return tmp;
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
