/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:16:25 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 02:54:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
AMateria::AMateria(void) {
	return ;
}

AMateria::AMateria(const AMateria& src) {
	*this = src;
	return ;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	return ;
}

AMateria::~AMateria(void) {
	return ;
}

// METHOD |=====================================================================
void	AMateria::use(ICharacter& target) {
	(void) target;
	std::cout << "Base use method of a Material" << std::endl;
	return ;
}

// OPERATOR |===================================================================
AMateria&	AMateria::operator=(const AMateria& sign) {
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================
const std::string&	AMateria::getType(void) const {
	return this->_type;
}
