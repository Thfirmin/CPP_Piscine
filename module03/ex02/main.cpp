/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:43:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 01:05:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap	clap("alan");
	ClapTrap	clap2("alan");
	ScavTrap	scav("alan");
	ScavTrap	scav2("alan");
	FragTrap	frag("alan");
	FragTrap	frag2("alan");

	std::cout << ClapTrap::getCtList() << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	return 0;
}

