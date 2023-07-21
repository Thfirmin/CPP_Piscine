/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:46:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 19:55:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*brian = newZombie("brian");
	Zombie	&cp = *brian;

	randomChump("Mike");
	cp.announce();
	delete brian;
	return 0;
}
