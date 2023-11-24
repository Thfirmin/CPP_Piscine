/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <t	hfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:54:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/23 20:58:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <stdexcept>
# include <cstdlib>

class Date {
	public:
		Date(void);
		Date(short int day, short int month, short int year, char separator);
		Date(const std::string &date, char separator);
		Date(Date const &src);
		~Date(void);

		Date			&operator=(Date const &src);
		bool			operator==(Date const &src) const;
		bool			operator!=(Date const &src) const;
		bool			operator<(Date const &src) const;
		bool			operator<=(Date const &src) const;
		bool			operator>(Date const &src) const;
		bool			operator>=(Date const &src) const;
		Date&			operator++(void);
		Date			operator++(int);
		Date&			operator--(void);
		Date			operator--(int);

		size_t			dateToDays(void) const;
		void			daysToDate(size_t days);

		short int			getDay(void) const;
		short int			getMonth(void) const;
		short int			getYear(void) const;
		char				getSeparator(void) const;
		const std::string	toString(void) const;

		void			setDay(short int day);
		void			setMonth(short int month);
		void			setYear(short int year);
		void			setSeparator(char separator);

	private:
		unsigned short int		_day;
		unsigned short int		_month;
		unsigned short int		_year;
		char					_separator;

		static short int		_getDayMax(short int month, short int year);
		static bool				_isLeapYear(short int year);
		static bool				_isValidDate(short int day, short int month, short int year);
		static bool				_isValidSeparator(char separator);
		static short int		_getActualDay(void);
		static short int		_getActualMonth(void);
		static short int		_getActualYear(void);
};

#endif // DATE_HPP
