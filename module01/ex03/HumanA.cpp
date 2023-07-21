/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:04:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/21 01:30:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(_weapon) {
	return ;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::setWeapon(std::string _type) {
	this->weapon.setType(_type);
	return ;
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}
