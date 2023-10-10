/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:32:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 09:05:27 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(int argc, char *argv[])
{
	int	grade = 150;

	if (argc > 1) {
		grade = atoi(*(argv + 1));
	}
	try
	{
		Bureaucrat	man("thino", grade);
		Intern					intern;
		AForm*					sform;
		AForm*					rform;
		AForm*					pform;

		sform = intern.makeForm("Shrubbery Creation", "thino");
		rform = intern.makeForm("Robotomy Request", "thino");
		pform = intern.makeForm("Presidential Pardon", "thino");

		std::cout << std::endl << man << sform << rform << pform << std::endl;

		man.signForm(*sform);
		man.signForm(*rform);
		man.signForm(*pform);

		std::cout << std::endl << man << sform << rform << pform << std::endl;

		man.executeForm(*sform);
		man.executeForm(*rform);
		man.executeForm(*pform);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
