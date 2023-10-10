/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/08 23:08:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>

// CONSTRUCTOR * DESTRUCTOR |===================================================
AForm::AForm(void) : _name("AForm"), _requiredGradeToSign(AForm::authGrade(AFORM_MIN_GRADE)), _requiredGradeToExec(AForm::authGrade(AFORM_MIN_GRADE)), _sign(false) {
	return ;
}

AForm::AForm(const AForm& src) : _name(src.getName()), _requiredGradeToSign(AForm::authGrade(src.getRequiredGradeToSign())), _requiredGradeToExec(AForm::authGrade(src.getRequiredGradeToExec())) {
	*this = src;
	return ;
}

AForm::AForm(const std::string& name, const grade_t requiredGradeToSign, const grade_t requiredGradeToExec) : _name(name), _requiredGradeToSign(AForm::authGrade(requiredGradeToSign)), _requiredGradeToExec(AForm::authGrade(requiredGradeToExec)), _sign(false) {
	return ;
}

AForm::~AForm(void) {
	return ;
}

AForm::GradeTooHighException::GradeTooHighException(void) throw() : GradeException("Grade too high") {
	return ;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& context) throw() : GradeException("Grade too high: " + context) {
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(void) throw() : GradeException("Grade Too Low") {
	return ;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& context) throw() : GradeException("Grade too low: " + context) {
	return ;
}

// METHOD |=====================================================================
grade_t	AForm::authGrade(const grade_t grade) {
	std::stringstream	stream;

	stream << grade << " is out of boound.";
	if (grade < AFORM_MAX_GRADE) {
		stream << " Maximum is " << AFORM_MAX_GRADE;
		throw AForm::GradeTooHighException(stream.str());
	}
	if (grade > AFORM_MIN_GRADE) {
		stream << " Minimum is " << AFORM_MIN_GRADE;
		throw AForm::GradeTooLowException(stream.str());
	}
	return grade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->_requiredGradeToSign < bureaucrat.getGrade()) {
		std::stringstream stream;

		stream << "Need grade " << this->_requiredGradeToSign << " or higher to sign this form";
		throw AForm::GradeTooLowException(stream.str());
	}
	this->_sign = true;
}

// OPERATOR |===================================================================
AForm&	AForm::operator=(const AForm& src) {
	this->_sign = src.getSign();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm* log) {
	out << log->getName() << " (\e[34m" << &log << "\e[0m){" << std::endl;
	out << "\trequiredGradeToSign: \e[32m" << log->getRequiredGradeToSign() << "\e[0m" << std::endl;
	out << "\trequiredGradeToExec: \e[32m" << log->getRequiredGradeToExec() << "\e[0m" << std::endl;
	out << "\tsign: \e[32m" << (log->getSign() ? "True" : "False") << "\e[0m" << std::endl;
	out << "\ttarget: \e[32m" << log->getTarget() << "\e[0m" << std::endl;
	out << "}" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
const std::string&	AForm::getName(void) const {
	return (this->_name);
}

const std::string&	AForm::getTarget(void) const {
	return (this->_target);
}

grade_t				AForm::getRequiredGradeToSign(void) const {
	return (this->_requiredGradeToSign);
}

grade_t				AForm::getRequiredGradeToExec(void) const {
	return (this->_requiredGradeToExec);
}

bool				AForm::getSign(void) const {
	return (this->_sign);
}

void				AForm::setTarget(const std::string& target) {
	if (!target.size()) {
		return ;
	}
	this->_target = target;
	return ;
}

void				AForm::setSign(const bool sign) {
	this->_sign = sign;
}
