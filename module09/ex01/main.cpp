/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:56:30 by thfirmin          #+#    #+#             */
/*   Updated: 2024/01/28 05:12:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Rpn.hpp"

// expr example: 1 2 + 3 5 * /

int	main(int argc, char *argv[])
{
	(void) argc;
	//std::string	expr = "1 2 + 3 5 * /";

	//if (argc > 1)
	//	expr = *(argv + 1);

	try
	{
		int res = Rpn::calculate(*(argv + 1));
		std::cout << "Response: " << res << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	};

	return (0);
}
