/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:21:36 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:39:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>

// CONSTRUCTOR * DESTRUCTOR |===================================================
// AForm
AForm::AForm(void) : _target("form"), _name("AForm"), _gradeToSign(AForm::authGrade(AFORM_MIN_GRADE)), _gradeToExec(AForm::authGrade(AFORM_MIN_GRADE)), _sign(false) {
	return ;
}

AForm::AForm(const AForm& src) : _target(src.getTarget()), _name(src.getName()), _gradeToSign(AForm::authGrade(src.getGradeToSign())), _gradeToExec(AForm::authGrade(src.getGradeToExec())) {
	*this = src;
	return ;
}

AForm::AForm(const std::string target, const std::string& name, const grade_t gradeToSign, const grade_t gradeToExec) : _target(target), _name(name), _gradeToSign(AForm::authGrade(gradeToSign)), _gradeToExec(AForm::authGrade(gradeToExec)) {
	return ;
}

AForm::~AForm(void) {
	return ;
}

// // GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(void) throw() : GradeException("Form grade too high") {
	return ;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& context) throw() : GradeException("Form grade too high: " + context) {
	return ;
}

// // GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(void) throw() : GradeException("Form grade too low") {
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& context) throw() : GradeException("Form grade too low: " + context) {
	return ;
}

// METHOD |=====================================================================
// AForm
grade_t	AForm::authGrade(grade_t grade) {
	std::stringstream	stream;

	stream << grade << " is out of bound. ";
	if (grade < AFORM_MAX_GRADE) {
		stream << "maximum is " << AFORM_MAX_GRADE;
		throw AForm::GradeTooHighException(stream.str());
	}
	if (grade > AFORM_MIN_GRADE) {
		stream << "minimum is " << AFORM_MIN_GRADE;
		throw AForm::GradeTooLowException(stream.str());
	}
	return (grade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	std::stringstream	stream;

	if (bureaucrat.getGrade() > this->_gradeToSign) {
		stream << "Need grade " << this->_gradeToSign << " or higher to sign";
		throw AForm::GradeTooLowException(stream.str());
	}
	this->_sign = true;
}

void	AForm::authExecutorRequirements(const Bureaucrat& executor, const AForm* form) {
	if (!form->getSign()) {
		throw std::logic_error(std::string("This form must be signed to be executed").c_str());
	}
	else if (form->getGradeToExec() < executor.getGrade()) {
		std::stringstream	stream;

		stream << "Need grade " << form->getGradeToExec() << " or higher to execute";
		throw AForm::GradeTooLowException(stream.str());	
	}
	return ;
}

// OPERATOR |===================================================================
// AForm
AForm&	AForm::operator=(const AForm& src) {
	this->_sign = src.getSign();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm* src) {
	out << src->getName() << " (" << (void*)src << "){" << std::endl;
	out << "\ttarget: \e[32m" << src->getTarget() << "\e[0m" << std::endl;
	out << "\tgradeToSign: \e[32m" << src->getGradeToSign() << "\e[0m" << std::endl;
	out << "\tgradeToExec: \e[32m" << src->getGradeToExec() << "\e[0m" << std::endl;
	out	<< "\tsign: \e[32m" << (src->getSign() ? "True" : "False") << "\e[0m" << std::endl;
	out << "}";
	out << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
const std::string&	AForm::getTarget(void) const {
	return (this->_target);
}

const std::string&	AForm::getName(void) const {
		return (this->_name);
}

grade_t				AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

grade_t				AForm::getGradeToExec(void) const {
	return (this->_gradeToExec);
}

bool				AForm::getSign(void) const {
	return (this->_sign);
}

