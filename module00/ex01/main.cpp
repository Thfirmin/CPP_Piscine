/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:32:12 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 11:25:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cctype>
#include "PhoneBook.hpp"

PhoneBook	book;

void	setFakeInput(void);

int	main(int argc, char *argv[]) {

	std::string	cmd;

	if ((argc > 1) && argv[1] == std::string("debug"))
		setFakeInput();
	while (1) {
		cmd = PhoneBook::getInput("PhoneBook: ");
		for (size_t i = 0, len = cmd.size(); i < len; i ++)
			cmd[i] = std::toupper(cmd[i]);
		if (!cmd.compare("ADD\0"))
			book.addList();
		else if (!cmd.compare("SEARCH\0"))
			book.searchList();
		else if (!cmd.compare("EXIT\0"))
			break ;
		if (std::cin.eof())
			return 1;
	}
	return 0;
}

void	setFakeInput(void) {
	const std::string	tabFill[8][5] = {
		{"Thino", "Tsukimichi", "thinotsuki", "+666 (666) 6666-6666", "This world is a bug and the moon's her patch"},
		{"Thiago", "Firmino dos Santos", "thfirmin", "+55 21 999187619", "This world's a trash, but this trash's the treasure of my treasure"},
		{"Thawan", "Camara", "tde-souz", "23 9800-1234", "Nobody known, but my expected life my expected lifetime is about 28 years :3"},
		{"Cuelho", "Lima", "llima", "-22(22)22222-2222", "Don't buy a glass without tin, it's amation!"},
		{"Aracely", "Mamani Puma", "cely", "+00 (00) 0000-0000", "Papito... ~<3"},
		{"Leticia", "Guimaraes", "smurfette", "+1234567890", "You was my first in a lot"},
		{"Fernanda", "Crispim", "ren", "+69 69 6969-9696", "I don't knou if is, just know if i fell"},
		{"Akine", "Yumeko", "akine", "+123 45 6789-1011", "Ask about all, the minor details'll give you the greater meanings"}
	};
	Contact	contact;

	for (int i = 0, max = PhoneBook::getLimit(); i < max; i ++) {
		contact.setFirstName(tabFill[i][0]);
		contact.setLastName(tabFill[i][1]);
		contact.setNickName(tabFill[i][2]);
		contact.setPhoneNumber(tabFill[i][3]);
		contact.setDarkestSecret(tabFill[i][4]);
		book.setContact(i, contact);
		book.setAmount(book.getAmount() + 1);
	}
	return ;
}
