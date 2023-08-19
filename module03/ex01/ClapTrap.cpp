/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:17:29 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/19 02:54:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// ATRIBUTE |===================================================================

const std::string	ClapTrap::_stdName = "clapTrap";
const int	ClapTrap::_stdHitPoints = 10;
const int	ClapTrap::_stdEnergyPoints = 10;
const int	ClapTrap::_stdAttackDamage = 0;

ClapTrapList*	ClapTrap::_clapTrapList = 0;

// CONSTRUCTOR * DESTRUCTOR |===================================================

ClapTrap::ClapTrap( void ) : _hitPoints(_stdHitPoints), _energyPoints(_stdEnergyPoints), _attackDamage(_stdAttackDamage) {
	this->setName(std::string(_stdName));
	ClapTrap::_ctlPush( this );
	std::cout << this->_name << ": ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const& src ) {
	*this = src;
	ClapTrap::_ctlPush( this );
	std::cout << this->_name << ": ClapTrap copy constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) : _hitPoints(_stdHitPoints), _energyPoints(_stdEnergyPoints), _attackDamage(_stdAttackDamage) {
	this->setName( name );
	ClapTrap::_ctlPush( this );
	std::cout << this->_name << ": ClapTrap named constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap( void ) {
	ClapTrap::_ctlDelete( this );
	std::cout << this->_name << ": ClapTrap destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================

void	ClapTrap::attack( std::string const& target ) {
	if (!this->_hitPoints || !this->_energyPoints)
		return ;

	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;

	this->setEnergyPoints(this->_energyPoints - 1);

	ClapTrap*	enemy = ClapTrap::_ctlPull(target);
	if (enemy)
		enemy->takeDamage(this->_attackDamage);
	else
		std::cout << "You did not hit your attack at all" << std::endl;

	return ;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (!this->_hitPoints)
		return ;
	
	std::cout << "ClapTrap " << this->_name << " is attacked, taking " << amount << " points of damage!" << std::endl;

	this->setHitPoints(this->_hitPoints - amount);

	return ;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (!this->_hitPoints || !this->_energyPoints)
		return ;

	std::cout << "ClapTrap " << this->_name << " is repaired , receiving " << amount << " hit points!" << std::endl;

	this->setEnergyPoints(this->_energyPoints - 1);
	this->setHitPoints(this->_hitPoints + amount);

	return ;
}

void	ClapTrap::_ctlPush( ClapTrap* inst ) {
	ClapTrapList* node = new ClapTrapList;
	node->inst = inst;
	node->next = 0;

	if (!_clapTrapList)
		_clapTrapList = node;
	else {
		ClapTrapList* lst = _clapTrapList;
		while (lst->next)
			lst = lst->next;
		lst->next = node;
	}
	return ;
}

void	ClapTrap::_ctlDelete( ClapTrap* inst ) {
	ClapTrapList*	node = _clapTrapList;
	ClapTrapList*	aux = node->next;

	if (node->inst == inst) {
		_clapTrapList = aux;
		delete node;
	}
	else {
		while (aux) {
			if (aux->inst == inst) {
				node->next = aux->next;
				delete aux;
				return ;
			}
			node = aux;
			aux = aux->next;
		}
	}
	return ;
}

ClapTrap*	ClapTrap::_ctlPull( std::string const& name ) {
	ClapTrapList*	list = _clapTrapList;

	while (list) {
		if (list->inst->getName() == name)
			return list->inst;
		list = list->next;
	}
	return 0;
}

std::string	ClapTrap::_ctlAuthName( std::string const& name ) {
	bool			auth = false;
	std::string		authName(name);
	ClapTrapList*	list;

	while (!auth) {
		auth = true;
		list = _clapTrapList;
		while (list) {
			if (authName == list->inst->getName()) {
				auth = false;
				authName += "0";
				break ;
			}
			list = list->next;
		}
	}
	return authName;
}

// OPERATOR |===================================================================

ClapTrap&	ClapTrap::operator=( ClapTrap const& sign ) {
	this->setName(sign.getName());
	this->setHitPoints(sign.getHitPoints());
	this->setEnergyPoints(sign.getEnergyPoints());
	this->setAttackDamage(sign.getAttackDamage());
	return *this;
}

std::ostream&	operator<<( std::ostream& out, ClapTrap const& clap ) {
	out << "(" << clap.getName() << ")";
	out << "[" << &clap << "]> ";
	out << "HP: " << clap.getHitPoints() << " | ";
	out << "EP: " << clap.getEnergyPoints() << " | ";
	out << "ATK:" << clap.getAttackDamage() << " | ";
	out << std::endl;
	return out;
}

std::ostream&	operator<<( std::ostream& out, ClapTrapList const* list ) {
	int	i = 0;

	while (list) {
		out << "bot[" << ++i << "]: ";
		out << *list->inst;
		list = list->next;
	}
	return out;
}

// GETTER * SETTER |============================================================

const std::string&	ClapTrap::getName( void ) const {
	return this->_name;
}

void	ClapTrap::setName( const std::string& name ) {
	this->_name = name;
	return ;
}

const int&	ClapTrap::getHitPoints( void ) const {
	return this->_hitPoints;
}

void	ClapTrap::setHitPoints( const int& hitPoints ) {
	if (hitPoints < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = hitPoints;
	return ;
}

const int&	ClapTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

void	ClapTrap::setEnergyPoints( const int& energyPoints ) {
	if (energyPoints < 0)
		this->_energyPoints = 0;
	else
		this->_energyPoints = energyPoints;
	return ;
}

const int&	ClapTrap::getAttackDamage( void ) const {
	return this->_attackDamage;
}

void	ClapTrap::setAttackDamage( const int& attackDamage ) {
	this->_attackDamage = attackDamage;
	return ;
}

ClapTrapList*	ClapTrap::getClapTrapList( void ) {
	return ClapTrap::_clapTrapList;
}
