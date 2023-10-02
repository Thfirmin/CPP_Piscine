/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:11:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 23:12:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	thino("Thino", 150);
		ShrubberyCreationForm	sform("stest");
		RobotomyRequestForm		rform("rtest");
		PresidentialPardonForm	pform("ptest");

		std::cout << thino << &sform << &rform << &pform;

		thino.signForm(sform);
		thino.signForm(rform);
		thino.signForm(pform);

		std::cout << thino << &sform << &rform << &pform;

		thino.executeForm(sform);
		thino.executeForm(rform);
		thino.executeForm(pform);

		return (0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (2);
	};
}
