/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:30 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 03:32:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		// Constructor/Destructor
		Contact(void);
		~Contact(void);

		// Getter
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickName(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getDarkestSecret(void) const;
		
		// Setter
		void		setFirstName(const std::string& name);
		void		setLastName(const std::string& lastName);
		void		setNickName(const std::string& nickName);
		void		setPhoneNumber(const std::string& phoneNumber);
		void		setDarkestSecret(const std::string& darkestSecret);
		void		setContact(const Contact& contact);
};

#endif
