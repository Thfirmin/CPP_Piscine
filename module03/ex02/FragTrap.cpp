/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:34:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/19 02:41:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// ATRIBUTE |===================================================================

const std::string	FragTrap::_stdName = "fragTrap";
const int	FragTrap::_stdHitPoints = 100;
const int	FragTrap::_stdEnergyPoints = 100;
const int	FragTrap::_stdAttackDamage = 30;

// CONSTRUCTOR * DESTRUCTOR |===================================================

FragTrap::FragTrap( void ) : ClapTrap() {
	this->setName(FragTrap::_stdName);
	this->setHitPoints(FragTrap::_stdHitPoints);
	this->setEnergyPoints(FragTrap::_stdEnergyPoints);
	this->setAttackDamage(FragTrap::_stdAttackDamage);
	std::cout << this->_name << ": FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const& src ) : ClapTrap(src) {
	*this = src;
	std::cout << this->_name << ": FragTrap copy constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->setHitPoints(FragTrap::_stdHitPoints);
	this->setEnergyPoints(FragTrap::_stdEnergyPoints);
	this->setAttackDamage(FragTrap::_stdAttackDamage);
	std::cout << this->_name << ": FragTrap named constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout << this->_name << ": FragTrap destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================


void	FragTrap::highFivesGuys( void ) {
	std::cout <<  "FragTrap " << this->getName() << " Request a High five: High five, buddy! Fragtrap has no friends.... Or hands." << std::endl;
	return ;
}

// OPERATOR |===================================================================

FragTrap&	FragTrap::operator=( FragTrap const& sign ) {
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}

// GETTER * SETTER |============================================================
