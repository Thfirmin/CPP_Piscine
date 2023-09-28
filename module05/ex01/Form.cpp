/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:32:59 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/27 22:15:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <sstream>
#include "Bureaucrat.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Form::Form(void) : _name("default"), _gradeToSign(FRM_MIN_GRADE), _gradeToExec(FRM_MIN_GRADE), _sign(false) {
	Form::validateGrade(this->_gradeToSign);
	Form::validateGrade(this->_gradeToExec);
	return ;
}

Form::Form(const std::string& name, const grade_t gradeToSign, const grade_t gradeToExec, const bool sign) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _sign(sign) {
	Form::validateGrade(this->_gradeToSign);
	Form::validateGrade(this->_gradeToExec);
	return ;
}

Form::Form(const Form& src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {
	Form::validateGrade(this->_gradeToSign);
	Form::validateGrade(this->_gradeToExec);
	*this = src;
	return ;
}

Form::~Form(void) {
	return ;
}

Form::GradeTooHighException::GradeTooHighException(void) throw() {
	this->_context = "\e[31mForm Error\e[0m: Grade Too High\n";
	return ;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& context) throw() {
	this->_context = "\e[31mForm Error\e[0m: Grade Too High: ";
	this->_context.append(context).append("\n");
	return ;
}

Form::GradeTooHighException::~GradeTooHighException(void) throw() {
	return ;
}

Form::GradeTooLowException::GradeTooLowException(void) throw() {
	this->_context = "\e[31mForm Error\e[0m: Grade Too Low\n";
	return ;
}

Form::GradeTooLowException::GradeTooLowException(const std::string& context) throw() {
	this->_context = "\e[31mForm Error\e[0m: Grade Too Low: ";
	this->_context.append(context).append("\n");
	return ;
}

Form::GradeTooLowException::~GradeTooLowException(void) throw() {
	return ;
}

// METHOD |=====================================================================
void		Form::beSigned(Bureaucrat& assignment) {
	if (assignment.getGrade() > this->_gradeToSign) {
		throw Form::GradeTooLowException();
	}
	this->setSign(true);
	return ;
}

void		Form::validateGrade(const grade_t grade) {
	std::stringstream	stream;

	stream << grade << " is out of bounds";
	if (grade < FRM_MAX_GRADE) {
		stream << ". Maximum is " << FRM_MAX_GRADE;
		throw Form::GradeTooHighException(stream.str());
	}
	else if (grade > FRM_MIN_GRADE) {
		stream << ". Minimum is " << FRM_MIN_GRADE;
		throw Form::GradeTooLowException(stream.str());
	}
	return ;
}

const char*	Form::GradeTooHighException::what(void) const throw() {
	return (this->_context.c_str());
}

const char*	Form::GradeTooLowException::what(void) const throw() {
	return (this->_context.c_str());
}

// OPERATOR |===================================================================
Form&	Form::operator=(const Form& src) {
	this->setSign(src.getSign());
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& src) {
	out << "\e[32m" << src.getName() << "\e[0m Form (\e[34m" << &src << "\e[0m) {" << std::endl;
	out << "\tgradeToSign:\e[32m" << src.getGradeToSign() << "\e[0m" << std::endl;
	out << "\tgradeToExec:\e[32m" << src.getGradeToExec() << "\e[0m" << std::endl;
	out << "\tsign:\e[32m" << src.getSign() << "\e[0m" << std::endl;
	out << "}" << std::endl;

	return (out);
}

// GETTER * SETTER |============================================================
const std::string	Form::getName(void) const {
	return (this->_name);
}

grade_t		Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

grade_t		Form::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

bool			Form::getSign(void) const {
	return (this->_sign);
}

void	Form::setSign(bool sign) {
	this->_sign = sign;
	return ;
}
