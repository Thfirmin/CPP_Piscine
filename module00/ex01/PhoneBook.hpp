/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:32:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/19 21:01:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook {
	private:
		static int		_limit;
		int				_amount;
		Contact			_contact[8];

		void				_displayPhoneBook(void);
		void				_displayContact(int i);
		static std::string	_formatContactInfo(std::string info);

	public:
		// Constructor/Destructor
		PhoneBook(void);
		~PhoneBook(void);

		// Getters
		static int	getLimit(void);
		int			getAmount(void) const;

		// Setters
		void		setAmount(int amount);
		void		setContact(int i, Contact account);

		// Utils
		void				searchList(void);
		void				addList(void);
		static std::string	getInput(std::string prompt);
};

#endif
