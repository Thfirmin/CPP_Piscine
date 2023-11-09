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

#include "C.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
C::C(void) {
	return ;
}

C::C(const C& src) {
	*this = src;
	return ;
}

C::~C(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
C&	C::operator=(const C& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const C& log) {
	out << "C (" << &log << ")" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================

// vim: ft=cpp
