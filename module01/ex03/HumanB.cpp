/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:06:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 23:54:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), weapon(0) {
	return ;
}

HumanB::~HumanB(void) {
	return ;
}

void	HumanB::setWeapon(Weapon& _weapon) {
	this->weapon = &_weapon;
	return ;
}

void	HumanB::attack(void) {
	std::string	type = "hands";

	if (this->weapon)
		type = this->weapon->getType();
	std::cout << this->name << " attacks with their " << type << std::endl;
	return ;
}
