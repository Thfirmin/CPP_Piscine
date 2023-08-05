/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:44:51 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:30:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Variables
CtList*	ClapTrap::_instList = 0;

// Constructor * Destructro 
ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	this->_name = ClapTrap::_authName("ClapTrap");
	ClapTrap::_ctAddBack( this );
	std::cout << this->_name << ": Default Created for OPEN!" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	this->_name = ClapTrap::_authName(name);
	ClapTrap::_ctAddBack( this );
	std::cout << this->_name << ": Named Created for OPEN!" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const& src ) {
	*this = src;
	ClapTrap::_ctAddBack( this );
	std::cout << this->_name << ": Copied for OPEN!" << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	ClapTrap::_ctDeleteOne( this );
	std::cout << this->_name << ": Remember, robots! you are the next evolution! Until a human shuts them down." << std::endl;
	return ;
}

// Methods
void	ClapTrap::attack( const std::string& target ) {
	if (!this->_hitPoints || !this->_energyPoints)
		return ;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;	
	this->_energyPoints --;

	ClapTrap* clapTrap = ClapTrap::_getClapTrap(target);
	if (clapTrap)
		clapTrap->takeDamage(this->_attackDamage);
	else
		std::cout << "You did not hit your attack at all" << std::endl;

	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (!this->_hitPoints)
		return ;

	std::cout << "ClapTrap " << this->_name << " is attacked, taking " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;

	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (!this->_hitPoints || !this->_energyPoints)
		return ;

	std::cout << "ClapTrap " << this->_name << " is repaired , receiving " << amount << " hit points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints --;

	return ;
}

// Statics
std::string	ClapTrap::_authName( std::string const& name ) {
	std::string	authName = name;
	CtList*	list;
	bool	auth = false;

	while (!auth) {
		list = ClapTrap::_instList;
		auth = true;
		while (list) {
			if (list->clapTrap->getName() == authName) {
				authName += "0";
				auth = false;
				break ;
			}
			list = list->next;
		}
	}
	return authName;
}

void	ClapTrap::_ctAddBack( ClapTrap* clapTrap ) {
	CtList*	list = ClapTrap::_instList;

	if (!list)
		ClapTrap::_instList = new CtList(clapTrap);
	else {
		while (list->next) {
			list = list->next;
		}
		list->next = new CtList(clapTrap);
	}
}

void	ClapTrap::_ctDeleteOne( ClapTrap* clapTrap ) {
	CtList* list = ClapTrap::_instList;
	CtList*	aux = 0;

	if (ClapTrap::_instList->clapTrap == clapTrap) {
		ClapTrap::_instList = list->next;
		delete list;
		return ;
	}
	while (list) {
		if (list->clapTrap == clapTrap) {
			aux->next = list->next;
			delete list;
			return ;
		}
		aux = list;
		list = list->next;
	}
	return ;
}

// Operators
ClapTrap&	ClapTrap::operator=( ClapTrap const& sign ) {
	this->_name = ClapTrap::_authName(sign.getName());
	this->_hitPoints = sign.getHitPoints();
	this->_energyPoints = sign.getEnergyPoints();
	this->_attackDamage = sign.getAttackDamage();
	return *this;
}

std::ostream&	operator<<( std::ostream& out, ClapTrap const& ct ) {
	out << "(" << ct.getName() << "): ";
	out << "| HP: " << ct.getHitPoints();
	out << "| EP: " << ct.getEnergyPoints();
	out << "| ATK: " << ct.getAttackDamage();
	out << " |" << std::endl;
	return out;
}

std::ostream&	operator<<( std::ostream& out, CtList* ctList ) {
	int	i = 0;
	out << std::endl << "----------| Clap Trap List |----------" << std::endl;
	while (ctList) {
		out << "node[" << i++ << "]: ";
		out << *ctList->clapTrap;
		ctList = ctList->next;
	}
	out << "--------------------------------------" << std::endl;
	return out;
}

// Getter * Setter
std::string	ClapTrap::getName( void ) const {
	return this->_name;
}

void	ClapTrap::setName( std::string name ) {
	this->_name = name;
}

int	ClapTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

void	ClapTrap::setHitPoints( int hitPoints ) {
	this->_hitPoints = hitPoints;
	return ;
}

int	ClapTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

void	ClapTrap::setEnergyPoints( int energyPoints ) {
	this->_energyPoints = energyPoints;
	return ;
}

int	ClapTrap::getAttackDamage( void ) const {
	return this->_attackDamage;
}

void	ClapTrap::setAttackDamage( int attackDamage ) {
	this->_attackDamage = attackDamage;
	return ;
}

CtList*	ClapTrap::getCtList( void ) {
	return ClapTrap::_instList;
}

ClapTrap*	ClapTrap::_getClapTrap( std::string const& name ) {
	CtList*	list = ClapTrap::_instList;

	while (list) {
		if (list->clapTrap->getName() == name)
			return list->clapTrap;
		list = list->next;
	}
	return 0;
}

// struct CtList
CtList::CtList( ClapTrap* clapTrap ) : clapTrap(clapTrap), next(0) {
	return ;
}

CtList::~CtList( void ) {
	return ;
}
