/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 05:36:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

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
void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (AForm::authExec(*this, bureaucrat)) {

		
		std::ofstream	targetFile(std::string(this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);
		
		if (!targetFile.is_open()) {
			throw std::logic_error(std::string(this->getTarget() + "_shrubbery: File don't open").c_str());
		}

		targetFile << "                                              .    " << std::endl;
		targetFile << "                                   .         ;     " << std::endl;
		targetFile << "      .              .              ;%     ;;      " << std::endl;
		targetFile << "        ,           ,                :;%  %;       " << std::endl;
		targetFile << "         :         ;                   :;%;'     .," << std::endl;
		targetFile << ",.        %;     %;            ;        %;'    ,;  " << std::endl;
		targetFile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'   " << std::endl;
		targetFile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'    " << std::endl;
		targetFile << "    ;%;      %;        ;%;        % ;%;  ,%;'      " << std::endl;
		targetFile << "     `%;.     ;%;     %;'         `;%%;.%;'        " << std::endl;
		targetFile << "      `:;%.    ;%%. %@;        %; ;@%;%'           " << std::endl;
		targetFile << "         `:%;.  :;bd%;          %;@%;'             " << std::endl;
		targetFile << "           `@%:.  :;%.         ;@@%;'              " << std::endl;
		targetFile << "             `@%.  `;@%.      ;@@%;                " << std::endl;
		targetFile << "               `@%%. `@%%    ;@@%;                 " << std::endl;
		targetFile << "                 ;@%. :@%%  %@@%;                  " << std::endl;
		targetFile << "                   %@bd%%%bd%%:;                   " << std::endl;
		targetFile << "                     #@%%%%%:;;                    " << std::endl;
		targetFile << "                     %@@%%%::;                     " << std::endl;
		targetFile << "                     %@@@%(o);  . '                " << std::endl;
		targetFile << "                     %@@@o%;:(.,'                  " << std::endl;
		targetFile << "                 `.. %@@@o%::;                     " << std::endl;
		targetFile << "                    `)@@@o%::;                     " << std::endl;
		targetFile << "                     %@@(o)::;                     " << std::endl;
		targetFile << "                    .%@@@@%::;                     " << std::endl;
		targetFile << "                    ;%@@@@%::;.                    " << std::endl;
		targetFile << "                   ;%@@@@%%:;;;.                   " << std::endl;
		targetFile << "               ...;%@@@@@%%:;;;;,..                " << std::endl;

		targetFile.close();
	}
	return ;
}

// OPERATOR |===================================================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	this->setTarget(src.getTarget());
	this->setSign(src.getSign());
	return (*this);
}

// GETTER * SETTER |============================================================
