/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:34:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 01:05:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("FragTrap") {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << this->getName() << ": FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const& src ) : ClapTrap(src) {
	*this = src;
	std::cout << this->getName() << ": FragTrap copy constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << this->getName() << ": FrapTrap named constructor called" << std::endl;
	return ;
}

FragTrap::~FragTrap( void ) {
	std::cout << this->getName() << ": FragTrap destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout <<  "FragTrap " << this->getName() << " Request a High five: High five, buddy! Fragtrap has no friends.... Or hands." << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=( FragTrap const& sign ) {
	this->setName(ClapTrap::_authName(sign.getName()));
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}
