/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:49:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/20 08:01:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Animal::Animal(void) {
	std::cout << "Animal: Default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& src) {
	*this = src;
	std::cout << "Animal: Copy constructor called" << std::endl;
	return ;
}

Animal::~Animal(void) {
	std::cout << "Animal: Destructor called" << std::endl;
	return ;
}

// OPERATOR |===================================================================
Animal&	Animal::operator=(const Animal& sign) {
	this->type = sign.getType();
	return *this;
}

// GETTE * SETTER |=============================================================
const std::string&	Animal::getType(void) const {
	return this->type;
}

void	Animal::setType(const std::string& _type) {
	this->type = _type;
	return ;
}
