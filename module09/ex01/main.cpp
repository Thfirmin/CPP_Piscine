/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:56:30 by thfirmin          #+#    #+#             */
/*   Updated: 2024/01/06 14:58:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Rpn.hpp"

int	main(int argc, char *argv[])
{
	std::string	expr = "1 2 + 3 5 * /";

	if (argc > 1)
		expr = *(argv + 1);

	try
	{
		Rpn::load(expr);
		Rpn::start();
		int res = Rpn::getResponse();
		std::cout << "Response: " << res << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	};

	return (0);
}
