/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 21:37:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Serializer::Serializer(void) {
	return ;
}

Serializer::Serializer(const Serializer& src) {
	*this = src;
	return ;
}

Serializer::~Serializer(void) {
	return ;
}

// METHOD |=====================================================================
uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

// OPERATOR |===================================================================
Serializer&	Serializer::operator=(const Serializer& src) {
	(void) src;
	return (*this);
}

// GETTER * SETTER |============================================================
