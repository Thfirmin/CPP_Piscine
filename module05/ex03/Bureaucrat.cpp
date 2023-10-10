/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/04 17:14:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>
#include "AForm.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(Bureaucrat::authGrade(BUREAUCRAT_MIN_GRADE)) {
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()) {
	*this = src;
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, const grade_t grade) : _name(name), _grade(Bureaucrat::authGrade(grade)) {
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

GradeException::GradeException(void) throw() : _context("GradeException") {
	return ;
}

GradeException::GradeException(const std::string& context) throw() : _context(context) {
	return ;
}

GradeException::~GradeException(void) throw() {
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() : GradeException("Grade too high") {
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& context) throw() : GradeException("Grade too high: " + context) {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() : GradeException("Grade too low") {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& context) throw() : GradeException("Grade too low: " + context) {
	return ;
}

// METHOD |=====================================================================
grade_t	Bureaucrat::authGrade(grade_t grade) {
	std::stringstream	stream;

	stream << grade << " is out of bound.";
	if (grade < BUREAUCRAT_MAX_GRADE) {
		stream << " Maximum is " << BUREAUCRAT_MAX_GRADE;
		throw Bureaucrat::GradeTooHighException(stream.str());
	}
	if (grade > BUREAUCRAT_MIN_GRADE) {
		stream << " Minimum is " << BUREAUCRAT_MIN_GRADE;
		throw Bureaucrat::GradeTooLowException(stream.str());
	}
	return (grade);
}

void	Bureaucrat::incrementGrade(void) {
	this->_grade = Bureaucrat::authGrade(this->_grade - 1);
	return ;
}

void	Bureaucrat::decrementGrade(void) {
	this->_grade = Bureaucrat::authGrade(this->_grade + 1);
	return ;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

const char*	GradeException::what(void) const throw() {
	return (this->_context.c_str());
}

// OPERATOR |===================================================================
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	this->_grade = Bureaucrat::authGrade(src.getGrade());
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& log) {
	out << log.getName() << ", bureaucrat grade " << log.getGrade() << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
const std::string&	Bureaucrat::getName(void) const {
	return this->_name;
}

grade_t				Bureaucrat::getGrade(void) const {
	return this->_grade;
}

