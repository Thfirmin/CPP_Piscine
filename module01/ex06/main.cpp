/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:58:53 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 10:25:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: " << *argv << " <level>" << std::endl;
		return 1;
	}
	Harl	harl;

	harl.levelFilter(argv[1]);
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("ERROR");
	harl.complain("errora");
	return 0;
}
