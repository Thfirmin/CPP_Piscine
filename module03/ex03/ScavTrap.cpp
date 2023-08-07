/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:16:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 00:54:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// ATRIBUTE |===================================================================

const std::string	ScavTrap::_stdName = "scavTrap";
const int	ScavTrap::_stdHitPoints = 100;
const int	ScavTrap::_stdEnergyPoints = 50;
const int	ScavTrap::_stdAttackDamage = 20;

// CONSTRUCTOR * DESTRUCTOR |===================================================

ScavTrap::ScavTrap( void ) : ClapTrap() {
	this->setName(ScavTrap::_stdName);
	this->setHitPoints(ScavTrap::_stdHitPoints);
	this->setEnergyPoints(ScavTrap::_stdEnergyPoints);
	this->setAttackDamage(ScavTrap::_stdAttackDamage);
	std::cout << this->_name << ": ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap(src) {
	*this = src;
	std::cout << this->_name << ": ScavTrap copy constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->setHitPoints(ScavTrap::_stdHitPoints);
	this->setEnergyPoints(ScavTrap::_stdEnergyPoints);
	this->setAttackDamage(ScavTrap::_stdAttackDamage);
	std::cout << this->_name << ": ScavTrap named constructor called" << std::endl;
	return ;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << this->_name << ": ScavTrap destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================

void	ScavTrap::guardGate( void ) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

// OPERATOR |===================================================================

ScavTrap&	ScavTrap::operator=( ScavTrap const& sign ) {
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}
