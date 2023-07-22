/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 02:02:10 by thfirmin         ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

// Public Functions
void	Harl::complain( std::string level ) {
	void	(Harl::*msg[Harl::nbTypes])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	const std::string	tabLvl[Harl::nbTypes] = {
		"debug",
		"info",
		"warning",
		"error",
	};

	for (int i = 0; level[i]; i ++)
		level[i] = std::tolower(level[i]);
	for (int i = 0; i < Harl::nbTypes; i ++) {
		if (level == tabLvl[i])
			(this->*msg[i])();
	}
	return ;
}

int	Harl::nbTypes = 4;
