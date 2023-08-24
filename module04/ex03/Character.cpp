/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:02:23 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 03:32:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Character::Character(void) {
	for (int i = 0; i < CHARACTER_MAX_INVENTORY; i ++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(const Character& src) {
	*this = src;
	return ;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < CHARACTER_MAX_INVENTORY; i ++)
		this->_inventory[i] = NULL;
	return ;
}

Character::~Character(void) {
	for (int i = 0; i < CHARACTER_MAX_INVENTORY; i ++)
		delete this->_inventory[i];
	return ;
}
// METHOD |=====================================================================
void	Character::equip(AMateria* m) {
	int idx = -1;

	while (++idx < CHARACTER_MAX_INVENTORY)
		if (!this->_inventory[idx])
			break ;
	if (idx != CHARACTER_MAX_INVENTORY)
		this->_inventory[idx] = m;
	return ;
}

void	Character::unequip(int idx) {
	// implement
	if (idx < 0 || idx >= CHARACTER_MAX_INVENTORY)
		return ;
	this->_inventory[idx] = NULL;
	return ;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= CHARACTER_MAX_INVENTORY)
		return ;
	this->_inventory[idx]->use(target);
	return ;
}

// OPERATOR |===================================================================
Character&	Character::operator=(const Character& sign) {
	// implement
	const AMateria*	m = 0;

	this->_name = sign.getName();
	for (int i = 0; i < CHARACTER_MAX_INVENTORY; i ++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		m = sign.getMateria(i);
		if (m)
			this->_inventory[i] = m->clone();
		else
			this->_inventory[i] = NULL;
	}
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================
const std::string&	Character::getName(void) const {
	return this->_name;
}

const AMateria*	Character::getMateria(int idx) const {
	if (idx < 0 || idx >= CHARACTER_MAX_INVENTORY)
		return 0;
	return this->_inventory[idx];
}
