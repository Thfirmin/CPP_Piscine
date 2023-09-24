/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 23:04:10 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/24 01:56:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Bureaucrat::Bureaucrat(void) : _name("default") {
	this->setGrade(BUREAUCRAT_HIGHEST_GRADE);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()), _grade(src.getGrade()) {
	return ;
}

Bureaucrat::Bureaucrat(const unsigned int grade) : _name("default") {
	this->setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int grade) : _name(name) {
	this->setGrade(grade);
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() {
	return ;
}

// METHOD |=====================================================================
void		Bureaucrat::incrementGrade(void) {
	this->setGrade(this->getGrade() - 1);
	return ;
}

void		Bureaucrat::decrementGrade(void) {
	this->setGrade(this->getGrade() + 1);
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("\e[31mError\e[0m: Grade Too High. Maximum is 1\n");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("\e[31mError\e[0m: Grade Too Low. Minimum is 150\n");
}

// OPERATOR |===================================================================
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& sign) {
	if (this != &sign) {
		this->setGrade(sign.getGrade());
	}
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return out;
}

// GETTER * SETTER |============================================================
const std::string&	Bureaucrat::getName(void) const {
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::setGrade(const unsigned int grade) {
	if (grade < BUREAUCRAT_HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > BUREAUCRAT_LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return ;
}
