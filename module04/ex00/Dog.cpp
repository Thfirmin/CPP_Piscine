/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:22:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/20 11:27:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Dog::Dog(void) : Animal() {
	std::cout << "Dog: Au!" << std::endl;
	return ;
}

Dog::Dog(const Dog& src) : Animal(src) {
	*this = src;
	std::cout << "Dog: Au Au!" << std::endl;
	return ;
}

Dog::~Dog(void) {
	std::cout << "Auu...!" << std::endl;
	return ;
}

// OPERATOR |===================================================================
Dog&	Dog::operator=(const Dog& sign) {
	(void) sign;
	return *this;
}
