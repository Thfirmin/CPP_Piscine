/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:28:53 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/20 12:58:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Cat::Cat(void) {
	std::cout << "Cat: Miau!" << std:endl;
	return ;
}

Cat::Cat(const Cat& src) {
	*this = src;
	std::cout << "Cat: Miau Miau!" << std::endl;
	return ;
}

Cat::~Cat(void) {
	std::cout << "Cat: Stick shooted" << std::endl;
}

// OPERATOR |===================================================================
Cat&	Cat::operator=(const Cat& sign) {
	(void) sign;
	return ;
}

// GETTER * SETTER |============================================================
