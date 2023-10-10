/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 05:38:12 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ATTRIBUTTE |=================================================================
const std::string	PresidentialPardonForm::_type = "PresidentialPardonForm";
const grade_t		PresidentialPardonForm::_stdGradeToSign = 25;
const grade_t		PresidentialPardonForm::_stdGradeToExec = 5;

// CONSTRUCTOR * DESTRUCTOR |===================================================
PresidentialPardonForm::PresidentialPardonForm(void) : AForm(PresidentialPardonForm::_type, PresidentialPardonForm::_stdGradeToSign, PresidentialPardonForm::_stdGradeToExec) {
	this->setTarget("home");
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(PresidentialPardonForm::_type, PresidentialPardonForm::_stdGradeToSign, PresidentialPardonForm::_stdGradeToExec) {
	*this = src;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(PresidentialPardonForm::_type, PresidentialPardonForm::_stdGradeToSign, PresidentialPardonForm::_stdGradeToExec) {
	this->setTarget(target);
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

// METHOD |=====================================================================
void	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
	if (AForm::authExec(*this, bureaucrat)) {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	return ;
}

// OPERATOR |===================================================================
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	this->setTarget(src.getTarget());
	this->setSign(src.getSign());
	return (*this);
}

// GETTER * SETTER |============================================================
