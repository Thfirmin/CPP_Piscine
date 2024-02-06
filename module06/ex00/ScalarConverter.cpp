/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/06 16:46:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

// METHOD |=====================================================================
void	ScalarConverter::convert(std::string literal) {
	t_dataType	dataType = newDataType();
	setScalarDataType(dataType, literal);
	std::cout << "ScalarConverter [\e[33m" << literal << "\e[0m] {" << std::endl;
	std::cout << "\tchar: \e[32m" << putChar(dataType) << "\e[0m" << std::endl;
	std::cout << "\tint: \e[32m" << putInt(dataType) << "\e[0m" << std::endl;
	std::cout << "\tfloat: \e[32m" << putFloat(dataType, literal) << "\e[0m" << std::endl;
	std::cout << "\tdouble: \e[32m" << putDouble(dataType, literal) << "\e[0m" << std::endl;
	std::cout << "}" << std::endl;
	return ;
}

// OPERATOR |===================================================================
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	(void) src;
	return (*this);
}

// GETTER * SETTER |============================================================
