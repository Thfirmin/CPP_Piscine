/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:31:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 08:58:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Intern::Intern(void) {
	return ;
}

Intern::Intern(const Intern& src) {
	*this = src;
	return ;
}

Intern::~Intern(void) {
	return ;
}

// METHOD |=====================================================================
AForm*	Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm*	form = 0;
	std::string	err_message(target + ": ");
	t_form	hash = Intern::hashForm(formName); 

	switch (hash) {
		case (shrubbery_creation):
			form = new ShrubberyCreationForm(target);
			if (!form) {
				err_message += "Can't alloc object";
				throw std::logic_error(err_message);
			}
			break ;
		case (robotomy_request):
			form = new RobotomyRequestForm(target);
			if (!form) {
				err_message += "Can't alloc object";
				throw std::logic_error(err_message);
			}
			break ;
		case (presidential_pardon):
			form = new PresidentialPardonForm(target);
			if (!form) {
				err_message += "Can't alloc object";
				throw std::logic_error(err_message);
			}
			break ;
		default:
			err_message += "Form don't exist";
			throw std::logic_error(err_message);
			break;
	};
	return (form);
}

t_form	Intern::hashForm(const std::string& form) {
	const std::string	form_db[] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"
	};
	int	hash = 0;

	while (hash != null_form) {
		if (form_db[hash] == form)
			break ;
		hash ++;
	}
	return ((t_form)hash);
}

// OPERATOR |===================================================================
Intern&	Intern::operator=(const Intern& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Intern& log) {
	out << "Intern (" << &log << ")" << std::endl;
	return (out);
}

