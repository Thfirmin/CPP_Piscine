/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:19:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:41:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

// CONSTRUCTOR * DESTRUCTOR |===================================================
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("form", "RobotomyRequestForm", 72, 45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src) {
	*this = src;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, "RobotomyRequestForm", 72, 45) {
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

// METHOD |=====================================================================
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::authExecutorRequirements(executor, this);

	srand(time(NULL));
	std::cout << "Robotomy: ZZZzzzzzzzzzzzzzzzzz.... ";
	if (rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else {
		std::cout << this->getTarget() << " robotomy fail" << std::endl;
	}
	return ;
}

// OPERATOR |===================================================================
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	(void) src;
	return (*this);
}

