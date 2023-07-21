/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 21:48:41 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 7;
	std::string name = "Dennis";
	Zombie* horde = zombieHorde(N, name);

	for (int i = 0; i < N; i ++)
		horde[i].announce();
	delete [] horde;
	return 0;
}
