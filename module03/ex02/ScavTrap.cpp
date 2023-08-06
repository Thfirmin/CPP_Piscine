/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:16:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 01:06:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("ScavTrap") {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << this->getName() << ": ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap(src) {
	*this = src;
	std::cout << this->getName() << ": ScaveTrap copy constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << this->getName() << ": ScavTrap named constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << this->getName() << ": ScavTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode: My helmet is my friend! It is the only one who understands me..." << std::endl;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const& sign ) {
	this->setName(ClapTrap::_authName(sign.getName()));
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}
