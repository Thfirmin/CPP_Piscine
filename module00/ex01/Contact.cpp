/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 03:30:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

const std::string&	Contact::getFirstName(void) const {
	return this->_firstName;
}

const std::string&	Contact::getLastName(void) const {
	return this->_lastName;
}

const std::string&	Contact::getNickName(void) const {
	return this->_nickName;
}

const std::string&	Contact::getPhoneNumber(void) const {
	return this->_phoneNumber;
}

const std::string&	Contact::getDarkestSecret(void) const {
	return this->_darkestSecret;
}

void	Contact::setFirstName(const std::string& firstName) {
	this->_firstName = firstName;
	return ;
}

void	Contact::setLastName(const std::string& lastName) {
	this->_lastName = lastName;
	return ;
}

void	Contact::setNickName(const std::string& nickName) {
	this->_nickName = nickName;
	return ;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->_phoneNumber = phoneNumber;
	return ;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->_darkestSecret = darkestSecret;
	return ;
}

void	Contact::setContact(const Contact& contact) {
	this->setFirstName(contact.getFirstName());
	this->setLastName(contact.getLastName());
	this->setNickName(contact.getNickName());
	this->setPhoneNumber(contact.getPhoneNumber());
	this->setDarkestSecret(contact.getDarkestSecret());
	return ;
}
