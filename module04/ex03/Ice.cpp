/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:51:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 02:59:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Ice::Ice(void) : AMateria("ice") {
	return ;
}

Ice::Ice(const Ice& src) : AMateria("ice") {
	*this = src;
	return ;
}

Ice::~Ice(void) {
	return ;
}

// METHOD |=====================================================================
Ice*	Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	(void) target;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}

// OPERATOR |===================================================================
Ice&	Ice::operator=(const Ice& sign) {
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================

