/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:43:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:31:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	clap("alan");
	ClapTrap	many("many");


	std::cout << clap;
	std::cout << many;
	many = clap;
	std::cout << clap;
	std::cout << many;
	many.attack("alan");
	clap.beRepaired(50);
	clap.guardGate();
	return 0;
}

