/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:49:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/23 17:06:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ATRIBUTES |==================================================================


// CONSTRUCTOR * DESTRUCTOR |===================================================
Animal::Animal(void) {
	this->brain = new Brain();
	std::cout << "\e[32mAnimal\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal& src) {
	this->brain = new Brain();
	*this = src;
	std::cout << "\e[32mAnimal\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

Animal::~Animal(void) {
	delete this->brain;
	std::cout << "\e[31mAnimal\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHODS |====================================================================

// STATICS |====================================================================


// OPERATOR |===================================================================
Animal&	Animal::operator=(const Animal& sign) {
	this->type = sign.getType();
	*this->brain = sign.getBrain();
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Animal& animal) {
	out << "Animal: " << animal.getType() << " [" << &animal << "]" << std::endl;
	out << animal.getBrain();
	return out;
}

// GETTER * SETTER |============================================================
const std::string&	Animal::getType(void) const {
	return this->type;
}

void	Animal::setType(const std::string& _type) {
	this->type = _type;
	return ;
}

Brain&	Animal::getBrain(void) const {
	return *this->brain;
}

void	Animal::setBrain(Brain& _brain) {
	delete this->brain;
	this->brain = new Brain(_brain);
}
