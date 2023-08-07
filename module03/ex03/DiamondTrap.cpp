/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:05:25 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 01:47:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// ATRIBUTE |===================================================================

const std::string	DiamondTrap::_stdName = "diamondTrap";
const int	DiamondTrap::_stdHitPoints = FragTrap::_stdHitPoints;
const int	DiamondTrap::_stdEnergyPoints = ScavTrap::_stdEnergyPoints;
const int	DiamondTrap::_stdAttackDamage = FragTrap::_stdAttackDamage;

// CONSTRUCTOR * DESTRUCTOR |===================================================

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap() {
	this->name = ClapTrap::ctlAuthName(DiamondTrap::_stdName);
	this->setName(this->name + "_clap_name");
	this->setHitPoints(DiamondTrap::_stdHitPoints);
	this->setEnergyPoints(DiamondTrap::_stdEnergyPoints);
	this->setAttackDamage(DiamondTrap::_stdAttackDamage);
	std::cout << this->_name << ": DiamondTrap default constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const& src ) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
	*this = src;
	std::cout << this->_name << ": DiamondTrap copy constructor called" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( std::string ) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	this->name = name;
	std::cout << this->_name << ": DiamondTrap named constructor called" << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << this->_name << ": DiamondTrap destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& sign ) {
	this->name = sign.getName();
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}

// GETTER * SETTER | ===========================================================
