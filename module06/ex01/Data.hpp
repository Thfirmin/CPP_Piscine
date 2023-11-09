/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 20:47:57 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	public:
		Data(void);
		Data(const Data& src);
		Data(const bool sign, const int id, const std::string& name);
		~Data(void);

		Data&	operator=(const Data& src);

		bool				getSign(void) const;
		int					getId(void) const;
		const std::string&	getName(void) const;

		void	setSign(const bool sign);
		void	setId(const int id);
		void	setName(const std::string& name);

	private:
		bool		_sign;
		signed int	_id;
		std::string	_name;
};

std::ostream&	operator<<(std::ostream& out, const Data& log);

#endif
