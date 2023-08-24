/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:26:12 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 03:39:14 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
MateriaSource::MateriaSource(void) {
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	*this = src;
	return ;
}

MateriaSource::~MateriaSource(void) {
	return ;
}

// METHOD |=====================================================================
void	MateriaSource::learnMateria(AMateria* m) {
	// implement
	(void) m;
	return ;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	// implement
	(void) type;
	return 0;
}

// OPERATOR |===================================================================
MateriaSource&	MateriaSource::operator=(const MateriaSource& sign) {
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================

