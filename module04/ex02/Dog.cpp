/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:22:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/23 16:43:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// ATRIBUTES |==================================================================


// CONSTRUCTOR * DESTRUCTOR |===================================================
Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "\e[32mDog\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& src) : Animal(src) {
	*this = src;
	std::cout << "\e[32mDog\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

Dog::~Dog(void) {
	std::cout << "\e[31mDog\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHODS |====================================================================
void	Dog::makeSound(void) const {
	std::cout << "\e[33mAu Au!\e[0m" << std::endl;
	return ;
}

// STATICS |====================================================================


// OPERATOR |===================================================================
Dog&	Dog::operator=(const Dog& sign) {
	this->type = sign.getType();
	return *this;
}

// GETTER * SETTER |============================================================

