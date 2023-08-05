/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:43:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 22:31:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	stepRound( ClapTrap& ct1, ClapTrap& ct2 );

int	main( void )
{
	ClapTrap	sand("SandMan");
	ClapTrap	slend("SlenderMan");

	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SendMan");

	stepRound(sand, slend);
	sand.setAttackDamage(2);
	slend.beRepaired(slend.getAttackDamage());

	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.setAttackDamage(1);

	stepRound(sand, slend);
	sand.attack("Slanderman");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.beRepaired(sand.getAttackDamage());
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");
	
	stepRound(sand, slend);
	sand.attack("SlenderMan");
	slend.attack("SandMan");

	return 0;
}

void	stepRound( ClapTrap& ct1, ClapTrap& ct2 ) {
	static int	round = 1;

	std::cout << "----------| Round " << round++ << " |----------" << std::endl;
	std::cout << ct1 << ct2;

}
