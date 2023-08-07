/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:43:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 01:25:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap	trap;
	DiamondTrap	trap2 = trap;
	std::cout << "HP: " << " | " << trap.ScavTrap::getEnergyPoints() << " | " << trap.FragTrap::getEnergyPoints() << std::endl;
	std::cout << "HP: " << " | " << trap2.ScavTrap::getEnergyPoints() << " | " << trap2.FragTrap::getEnergyPoints() << std::endl;
	std::cout << ClapTrap::getClapTrapList() << std::endl;
	return 0;
}

