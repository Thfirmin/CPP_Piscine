/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:25:09 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:41:43 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// CONSTRUCTOR * DESTRUCTOR |===================================================
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("form" ,"ShrubberyCreationForm", 145, 137){
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src) {
	*this = src;
	 return ;
}

	ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, "ShrubberyCreationForm", 145, 137) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

// METHOD |=====================================================================
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::authExecutorRequirements(executor, this);
	
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
	return ;
}

// OPERATOR |===================================================================
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	(void) src;
	return (*this);
}

