/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/18 00:22:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructors * Destructors
Harl::Harl( void ) {
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
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

// Public Functions
void	Harl::complain( std::string level ) {
	void	(Harl::*msg[Harl::_nbLevels])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < Harl::_nbLevels; i ++) {
		if (level == Harl::_levelTypes[i])
			(this->*msg[i])();
	}
	return ;
}

const int	Harl::_nbLevels = 4;

const std::string	Harl::_levelTypes[] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

