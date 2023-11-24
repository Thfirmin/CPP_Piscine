/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:07:15 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/23 19:46:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define CSV_FILE "data.csv"

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include <exception>
# include <unistd.h>
# include <cerrno>
# include <cstring>

class	DataBase {
	public:
		DataBase(void);
		DataBase(const std::string& csvFile);
		~DataBase(void);

		const std::string&	getCsvFile(void) const;
		std::ifstream&		openCsvFile(void);


	private:
		std::string		_csvFile;
		std::string		_parse;
		std::ifstream*	_stream;

		static std::string&	_authCsvFile(const std::string& file);
		void				_validDbFile(void);
		void				_closeCsvFile(void);
};

class	Date {
	public:
		Date(void);
		Date(const std::string& date);
		Date(const int day, const int month, const int year);
		Date(const std::string& str);
		Date(const Date& date);
		~Date(void);

		Date&	operator=(const Date& date);
		bool	operator>(const Date& date);
		bool	operator<(const Date& date);
		bool	operator>=(const Date& date);
		bool	operator<=(const Date& date);
		bool	operator==(const Date& date);
		bool	operator!=(const Date& date);
		Date&	operator++(void);
		Date	operator++(int);
		Date&	operator--(void);
		Date	operator++(int);

		size_t	dateToDay(const Date& date);
		size_t	dateToMonth(const Date& date);

		size_t	monthToDay(int month);
		size_t	yearToMonth(void);
		size_t	yearToDay(int day);

		int					getYear(void) const;
		int					getMonth(void) const;
		int					getDay(void) const;
		char				getSplit(void) const;
		const std::string&	getDate(void) const;

		void	setYear(const int);
		void	setMonth(const int);
		void	setDay(const int)
		void	setSplit(const char);
		void	setDate(const int day, const int month, const int year, const char split);
		void	setDate(const std::string& date);

	private:
		short int		_year;
		short int		_month;
		short int		_day;
		char			_split;

		void	parseDateString(const std::string& str);
		void	authDate(void);
}

DataBase*	dbInit(const char* dbFile);

#endif
