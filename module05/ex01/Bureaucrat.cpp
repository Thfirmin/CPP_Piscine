/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:19:51 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/27 22:14:59 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>
#include "Form.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Bureaucrat::Bureaucrat(void) : _name("default") {
	this->setGrade(BRCT_MIN_GRADE);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src.getName()) {
	*this = src;
	return ;
}

Bureaucrat::Bureaucrat(const std::string& name, grade_t grade): _name(name) {
	this->setGrade(grade);
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() {
	this->_context = "\e[31mBureaucrat Error\e[0m: Grade Too High\n";
	return ;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& context) throw() {
	(void) context;
	this->_context = "\e[31mBureaucrat Error\e[0m: Grade Too High: ";
	this->_context.append(context).append("\n");
	return ;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() {
	this->_context = "\e[31mBureaucrat Error\e[0m: Grade Too Low\n";
	return ;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& context) throw() {
	this->_context = "\e[31mBureaucrat Error\e[0m: Grade Too Low: ";
	this->_context.append(context).append("\n");
	return ;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}

// METHOD |=====================================================================
void		Bureaucrat::incrementGrade(void) {
	this->setGrade(this->_grade - 1);
	return ;
}

void		Bureaucrat::decrementGrade(void) {
	this->setGrade(this->_grade + 1);
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return (this->_context.c_str());
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return (this->_context.c_str());
}

void		Bureaucrat::signForm(Form& form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << form.getName() << " because " << e.what();
	}
}

// OPERATOR |===================================================================
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	this->setGrade(src.getGrade());
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << "." << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
const std::string&	Bureaucrat::getName(void) const {
	return (this->_name);
}

grade_t				Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void				Bureaucrat::setGrade(grade_t grade) {
	std::stringstream	stream;

	stream << "Can't set grade " << grade << ".";
	if (grade < BRCT_MAX_GRADE) {
		stream << " Maximum is " << BRCT_MAX_GRADE;
		throw Bureaucrat::GradeTooHighException(stream.str());
	}
	else if (grade > BRCT_MIN_GRADE) {
		stream << " Minimum is " << BRCT_MIN_GRADE;
		throw Bureaucrat::GradeTooLowException(stream.str());
	}
	this->_grade = grade;
	return ;
}

