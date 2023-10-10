/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/08 23:08:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ATTRIBUTE |==================================================================
const std::string	ShrubberyCreationForm::_type = "ShrubberyCreationForm";
const grade_t		ShrubberyCreationForm::_stdGradeToSign = 145;
const grade_t		ShrubberyCreationForm::_stdGradeToExec = 137;

// CONSTRUCTOR * DESTRUCTOR |===================================================
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(ShrubberyCreationForm::_type, ShrubberyCreationForm::_stdGradeToSign, ShrubberyCreationForm::_stdGradeToExec) {
	this->setTarget("home");
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(ShrubberyCreationForm::_type, ShrubberyCreationForm::_stdGradeToSign, ShrubberyCreationForm::_stdGradeToExec) {
	*this = src;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(ShrubberyCreationForm::_type, ShrubberyCreationForm::_stdGradeToSign, ShrubberyCreationForm::_stdGradeToExec) {
	this->setTarget(target);
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	this->setTarget(src.getTarget());
	this->setSign(src.getSign());
	return (*this);
}

// GETTER * SETTER |============================================================
