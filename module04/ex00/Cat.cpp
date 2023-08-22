/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:28:53 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 10:39:37 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// ATRIBUTES |==================================================================


// CONSTRUCTOR * DESTRUCTOR |===================================================
Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "\e[32mCat\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& src) : Animal(src) {
	*this = src;
	std::cout << "\e[32mCat\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

Cat::~Cat(void) {
	std::cout << "\e[31mCat\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHODS |====================================================================
void	Cat::makeSound(void) const {
	std::cout << "\e[33mMiau Miau!\e[0m" << std::endl;
	return ;
}

// STATICS |====================================================================


// OPERATOR |===================================================================
Cat&	Cat::operator=(const Cat& sign) {
	this->type = sign.getType();
	return *this;
}

// GETTER * SETTER |============================================================

