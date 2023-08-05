/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:16:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:24:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap(src) {
	*this = src;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "Named constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const& sign ) {
	this->setName(ClapTrap::_authName(sign.getName()));
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}
