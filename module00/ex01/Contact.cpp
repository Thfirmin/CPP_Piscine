/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:35:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

bool	Contact::getSign(void) const {
	return this->_sign;
}

std::string	Contact::getFirstName(void) const {
	return this->_firstName;
}

std::string	Contact::getLastName(void) const {
	return this->_lastName;
}

std::string	Contact::getNickName(void) const {
	return this->_nickName;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}


void	Contact::setSign(bool sign) {
	this->_sign = sign;
	return ;
}

void	Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
	return ;
}

void	Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
	return ;
}

void	Contact::setNickName(std::string nickName) {
	this->_nickName = nickName;
	return ;
}

void	Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
	return ;
}

void	Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
	return ;
}

void	Contact::setContact(Contact& contact) {
	this->_firstName = contact.getFirstName();
	this->_lastName = contact.getLastName();
	this->_nickName = contact.getNickName();
	this->_phoneNumber = contact.getPhoneNumber();
	this->_darkestSecret = contact.getDarkestSecret();
	return ;
}
