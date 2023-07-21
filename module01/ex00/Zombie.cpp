/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:47:30 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 19:54:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string _name ) : name(_name) {
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << "\e[1;31m" << this->name << " returned to the underground\e[m" << std::endl;
	return ;
}

void	Zombie::announce( void ) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
