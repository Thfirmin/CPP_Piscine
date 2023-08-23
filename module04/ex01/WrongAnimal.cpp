/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:50:41 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 10:59:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
WrongAnimal::WrongAnimal(void) {
	std::cout << "\e[32mWrongAnimal\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
	*this = src;
	std::cout << "\e[32mWrongAnimal\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "\e[31mWrongAnimal\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHODS |====================================================================
void	WrongAnimal::makeSound(void) const {
	std::cout << "\e[33mStandard Wrong Animal sound\e[0m" << std::endl;
	return ;
}

// OPERATOR |===================================================================
WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& sign) {
	this->type = sign.getType();
	return *this;
}

// GETTER * SETTER |============================================================
const std::string&	WrongAnimal::getType(void) const {
	return this->type;
}

void	WrongAnimal::setType(const std::string& _type) {
	this->type = _type;
	return ;
}
