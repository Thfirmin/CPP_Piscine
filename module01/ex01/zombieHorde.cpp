/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:49 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 22:05:39 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	std::stringstream indice;

	Zombie*	horde = new Zombie[N];
	for (int i = 0; i < N; i ++) {
		indice.str("");
		indice << i + 1;
		horde[i].setName(name + " " + indice.str());
	}
	return horde;
}
