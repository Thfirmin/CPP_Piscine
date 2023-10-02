/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:10:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:41:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("form", "PresidentialPardonForm", 25, 5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src) {
	*this = src;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, "PresidentialPardonForm", 25, 5) {
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

// METHOD |=====================================================================
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::authExecutorRequirements(executor, this);

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}

// OPERATOR |===================================================================
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	(void) src;
	return (*this);
}

