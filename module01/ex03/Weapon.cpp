/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:17:49 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 23:51:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type) {
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

std::string	Weapon::getType(void) const {
	return this->type;
}

void	Weapon::setType(std::string _type) {
	this->type = _type;
	return ;
}
