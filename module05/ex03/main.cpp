/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:32:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/08 23:29:41 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	man("thino", 1);
	ShrubberyCreationForm	sform("target");
	RobotomyRequestForm		rform("target");
	PresidentialPardonForm	pform("target");

	std::cout << man << &sform << &rform << &pform;

	try
	{
		man.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() <<std::endl;
	};
	std::cout << "Hello, World!" << std::endl;
	return (0);
}
