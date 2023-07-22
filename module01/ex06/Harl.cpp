/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 10:26:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructors * Destructors
Harl::Harl( void ) : _levelFilter(-1) {
	return ;
}

Harl::~Harl( void ) {
	return ;
}

// Private Functions
void	Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I really do!" << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl <<"I’ve been coming foryears whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

int	Harl::levelFilter( void ) const {
	return this->_levelFilter;
}

void	Harl::levelFilter( std::string level ) {
	int	lvl;

	lvl = Harl::isLevel(level);
	if (lvl < 0)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		this->_levelFilter = lvl;
	return ;
}

// Public Functions
void	Harl::complain( std::string level ) {
	int		i;
	void	(Harl::*msg[Harl::_nbLevels])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	i = Harl::isLevel(level);
	if ((this->_levelFilter >= 0) && (this->_levelFilter <= i)) {
		std::cout << "[ " << Harl::_levelTypes[i] << " ]" << std::endl;
		(this->*msg[i])();
		std::cout << std::endl;
	}
	return ;
}

// Static functions
int	Harl::isLevel( std::string level ) {
	for (int i = 0; level[i]; i ++)
		level[i] = std::toupper(level[i]);
	for (int i = 0; i < Harl::_nbLevels; i ++) {
		if (level == Harl::_levelTypes[i])
			return (i);
	}
	return -1;
}

const int	Harl::_nbLevels = 4;

const std::string	Harl::_levelTypes[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};
