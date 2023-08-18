/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 23:37:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : name("") {
	return ;
}

Zombie::Zombie( std::string _name ) : name(_name) {
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << "\e[1;31m" << this->name << " returned to the underground\e[m" << std::endl;
}

void	Zombie::setName( const std::string& name ) {
	this->name = name;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
