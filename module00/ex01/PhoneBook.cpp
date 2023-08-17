/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:09 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 03:17:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

int	PhoneBook::getLimit(void) {
	return PhoneBook::_limit;
}

int	PhoneBook::getAmount(void) const {
	return this->_amount;
}

std::string	PhoneBook::getInput(std::string prompt) {
	std::string	input;

	while (input.empty()) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			input.resize(0);
			return input;
		}
		for (size_t i = 0, len = input.size(); i < len; i ++) {
			if (!std::isspace(input[i]))
				break ;
			if (i == (len - 1))
				input.resize(0);
		}
	}
	return input;
}

void	PhoneBook::setAmount(int amount) {
	if (amount > PhoneBook::getLimit())
		return ;
	this->_amount = amount;
	return ;
}

void	PhoneBook::setContact(int i, Contact account) {
	this->_contact[i].setContact(account);
	return ;
}

void	PhoneBook::searchList(void) {
	std::string	input;
	int			idx;

	if (!this->getAmount())
		std::cout << "Your list seems empty, try \e[1;33mADD\e[m some contacts" << std::endl;
	else {
		this->_displayPhoneBook();
		while (input.empty()) {
			input = PhoneBook::getInput("Insert the looked index: ");
			if (std::cin.eof())
				return ;
			else if (input.empty())
				return ;
			for (size_t i = 0; i < input.size(); i ++) {
				if (!std::isdigit(input[i]))
					input.resize(0);
			}
		}
		idx = atoi(input.c_str());
		this->_displayContact(idx);
		return ;
	}
	return ;
}

void	PhoneBook::addList(void) {
	std::string	input;
	int			amount = this->getAmount();
	int			limit = PhoneBook::getLimit();

	if (amount == limit) {
		std::cout << "You've lotted the contact number capacity." << std::endl;
		std::cout << "To add a contact you'll lost your older contact." << std::endl;
		while (input.size() != 1) {
			std::cout << "are you sure? [Y/n] " << std::flush;
			std::getline(std::cin, input);
			if (std::cin.eof())
				return ;
			else if (input.empty())
				break ;
			input[0] = std::toupper(input[0]);
			if ((input[0] != 'Y') && (input[0] != 'N'))
				input.resize(0);
		}
		if (input[0] == 'N')
			return ;
	}

	for (int i = limit - 1; i > 0; i --)
		this->setContact(i, this->_contact[i - 1]);
	if (!std::cin.eof())
		this->_contact[0].setFirstName(PhoneBook::getInput("First Name: "));
	if (!std::cin.eof())
		this->_contact[0].setLastName(PhoneBook::getInput("Last Name: "));
	if (!std::cin.eof())
		this->_contact[0].setNickName(PhoneBook::getInput("Nick Name: "));
	if (!std::cin.eof())
		this->_contact[0].setPhoneNumber(PhoneBook::getInput("Phone Number: "));
	if (!std::cin.eof())
		this->_contact[0].setDarkestSecret(PhoneBook::getInput("Darkest Secret: "));
	if (amount < limit)
		this->setAmount(amount + 1);
	return ;
}

void	PhoneBook::_displayPhoneBook(void) {
	Contact	contact;

	std::cout << "\e[1;35m" << "_____________________________________________________" << "\e[m" << std::endl;
	std::cout << "\e[1;35m" << "|" << "\e[39;44m" << " ";
	std::cout << std::setw(10) << std::right << "Index";
	std::cout << "\e[1;35m" << " | " << "\e[39m";
	std::cout << std::setw(10) << std::right << "First Name";
	std::cout << "\e[1;35m" << " | " << "\e[39m";
	std::cout << std::setw(10) << std::right << "Last Name";
	std::cout << "\e[1;35m" << " | " << "\e[39m";
	std::cout << std::setw(10) << std::right << "Nick Name";
	std::cout << " " << "\e[35;49m" << "|" << "\e[m" << std::endl;
	for (int i = 0, max = this->getAmount(); i < max; i ++) {
		contact = this->_contact[i];
		std::cout << "\e[1;35m" << "|" << "\e[4;33;47m" << " " << std::setw(10) << std::right << i << " \e[m";
		std::cout << "\e[1;4;47;35m" << "|" << " \e[33m" << std::setw(10) << std::right << PhoneBook::_formatContactInfo(contact.getFirstName()) << " \e[m";
		std::cout << "\e[1;4;47;35m" << "|" << " \e[33m" << std::setw(10) << std::right << PhoneBook::_formatContactInfo(contact.getLastName()) << " \e[m";
		std::cout << "\e[1;4;47;35m" << "|" << " \e[33m" << std::setw(10) << std::right << PhoneBook::_formatContactInfo(contact.getNickName()) << " \e[m";
		std::cout << "\e[1;35;49m" << "|" << "\e[m" << std::endl;
	}
	return ;
}

void	PhoneBook::_displayContact(int i) {
	Contact contact;
	if ((i < 0) || (i >= this->getAmount()))
		std::cout << "Error: Inexistent Contact" << std::endl;
	else {
		contact = this->_contact[i];
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nick Name: " << contact.getNickName() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	}
	return ;
}

std::string	PhoneBook::_formatContactInfo(std::string info) {
	if (info.size() > 10) {
		info.replace(9, 1, ".");
		info.resize(10);
	}
	return info;
}

int	PhoneBook::_limit = PB_CONTACT_LIMITS; 
