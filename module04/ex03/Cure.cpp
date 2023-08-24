/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:54:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 02:59:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Cure::Cure(void) : AMateria("cure") {
	return ;
}

Cure::Cure(const Cure& src) : AMateria("cure") {
	*this = src;
	return ;
}

Cure::~Cure(void) {
	return ;
}

// METHOD |=====================================================================
Cure*	Cure::clone() const {
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	(void) target;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	return ;
}
// OPERATOR |===================================================================
Cure&	Cure::operator=(const Cure& sign) {
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================

