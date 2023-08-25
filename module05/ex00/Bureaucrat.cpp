/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:04:10 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 23:48:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Bureaucrat::Bureaucrat(const std::string& name, const unsigned int grade) : _name(name) {
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

// METHOD |=====================================================================
// OPERATOR |===================================================================
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& sign) {
	(void) sign;
	return *this;
}

// GETTER * SETTER |============================================================
const std::string&	Bureaucrat::getName(void) const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::setGrade(const unsigned int grade) {
	if (grade < BUREAUCRAT_HIGHEST_GRADE || grade > BUREAUCRAT_LOWEST_GRADE)
		return ;
	this->_grade = grade;
	return ;
}
