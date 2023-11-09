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

#include "A.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
A::A(void) {
	return ;
}

A::A(const A& src) {
	*this = src;
	return ;
}

A::~A(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
A&	A::operator=(const A& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const A& log) {
	out << "A (" << &log << ")" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================

// vim: ft=cpp
