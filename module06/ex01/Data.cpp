/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 20:52:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Data::Data(void) {
	return ;
}

Data::Data(const Data& src) {
	*this = src;
	return ;
}

Data::Data(const bool sign, const int id, const std::string& name): _sign(sign), _id(id), _name(name) {
	return ;
}

Data::~Data(void) {
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
Data&	Data::operator=(const Data& src) {
	(void) src;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Data& log) {
	out << "Data (" << &log << ") {" << std::endl;
	out << "\tsign: \e[32m" << log.getSign() << "\e[0m" << std::endl;
	out << "\tid:   \e[32m" << log.getId() << "\e[0m" << std::endl;
	out << "\tname: \e[32m" << log.getName() << "\e[0m" << std::endl;
	out << "}" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
bool	Data::getSign(void) const {
	return (this->_sign);
}

int	Data::getId(void) const {
	return (this->_id);
}

const std::string&	Data::getName(void) const {
	return (this->_name);
}

void	Data::setSign(const bool sign) {
	this->_sign = sign;
	return ;
}

void	Data::setId(const int id) {
	this->_id = id;
	return ;
}

void	Data::setName(const std::string& name) {
	this->_name = name;
	return ;
}
