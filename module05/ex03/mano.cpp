/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mano.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/04 17:14:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
main::main(void) {
	return ;
}

main::main(const main& src) {
	*this = src;
	return ;
}

main::~main(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
main&	main::operator=(const main& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const main& log) {
	out << "main (" << &log << ")" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
