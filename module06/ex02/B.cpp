/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 21:56:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
B::B(void) {
	return ;
}

B::B(const B& src) {
	*this = src;
	return ;
}

B::~B(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
B&	B::operator=(const B& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const B& log) {
	out << "B (" << &log << ")" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================

// vim: ft=cpp
