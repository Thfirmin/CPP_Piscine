/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:54:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/24 01:59:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	inst("thino", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	};
	
	try
	{
		Bureaucrat	inst("thino", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	};

	Bureaucrat	thino("thino", 2);
	try
	{
		std::cout << thino;
		thino.incrementGrade();
		std::cout << thino;
		thino.incrementGrade();
		std::cout << thino;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	};

	Bureaucrat	copy(thino);
	std::cout << copy;
	copy = Bureaucrat(149);
	try
	{
		std::cout << copy;
		copy.decrementGrade();
		std::cout << copy;
		copy.decrementGrade();
		std::cout << copy;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	};
	return (0);
}
