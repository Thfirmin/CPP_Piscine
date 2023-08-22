/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:49:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 10:39:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ATRIBUTES |==================================================================


// CONSTRUCTOR * DESTRUCTOR |===================================================
Animal::Animal(void) {
	std::cout << "\e[32mAnimal\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& src) {
	*this = src;
	std::cout << "\e[32mAnimal\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

Animal::~Animal(void) {
	std::cout << "\e[31mAnimal\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHODS |====================================================================
void	Animal::makeSound(void) const {
	std::cout << "\e[33mStandard animal sound method\e[0m" << std::endl;
	return ;
}

// STATICS |====================================================================


// OPERATOR |===================================================================
Animal&	Animal::operator=(const Animal& sign) {
	this->type = sign.getType();
	return *this;
}

// GETTER * SETTER |============================================================
const std::string&	Animal::getType(void) const {
	return this->type;
}

void	Animal::setType(const std::string& _type) {
	this->type = _type;
	return ;
}
