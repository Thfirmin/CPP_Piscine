/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 09:04:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

// ATTRIBUTTE |=================================================================
const std::string	RobotomyRequestForm::_type = "RobotomyRequestForm";
const grade_t		RobotomyRequestForm::_stdGradeToSign = 72;
const grade_t		RobotomyRequestForm::_stdGradeToExec = 45;

// CONSTRUCTOR * DESTRUCTOR |===================================================
RobotomyRequestForm::RobotomyRequestForm(void) : AForm(RobotomyRequestForm::_type, RobotomyRequestForm::_stdGradeToSign, RobotomyRequestForm::_stdGradeToExec) {
	this->setTarget("home");
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(RobotomyRequestForm::_type, RobotomyRequestForm::_stdGradeToSign, RobotomyRequestForm::_stdGradeToExec) {
	*this = src;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(RobotomyRequestForm::_type, RobotomyRequestForm::_stdGradeToSign, RobotomyRequestForm::_stdGradeToExec) {
	this->setTarget(target);
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

// METHOD |=====================================================================
void	RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	if (AForm::authExec(*this, bureaucrat)) {
		static char seed;
		if (!seed) {
			srand(time(NULL));
			seed++;
		}
		std::cout << "Robotomy: ZZZzzzzzzzzzzzzzzzzz.... ";
		if (rand() % 2) {
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
		}
		else {
			std::cout << this->getTarget() << " robotomy fail" << std::endl;
		}
	}
	return ;
}

// OPERATOR |===================================================================
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	this->setTarget(src.getTarget());
	this->setSign(src.getSign());
	return (*this);
}

// GETTER * SETTER |============================================================
