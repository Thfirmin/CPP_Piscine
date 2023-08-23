/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:03:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 10:59:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "\e[32mWrongCat\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) {
	*this = src;
	std::cout << "\e[32mWrongCat\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void) {
	std::cout << "\e[31mWrongCat\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================
void	WrongCat::makeSound(void) const {
	std::cout << "\e[33mWrongCat: Au Au!\e[0m" << std::endl;
	return ;
}

// OPERATOR |===================================================================
WrongCat&	WrongCat::operator=(const WrongCat& sign) {
	this->type = sign.getType();
	return *this;
}
