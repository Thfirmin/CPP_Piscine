/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:07:15 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/28 17:01:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define CSV_FILE "data.csv"
# define MAX_BLOCK_SIZE 1000

# include <iostream>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <string>

# include <stdexcept>
# include <exception>

# include <vector>
# include <algorithm>

# include <unistd.h>
# include <ctime>
# include <cstdlib>
# include <cerrno>
# include <cstring>

typedef unsigned short int usint;

class Date
{
	public:
		Date(void);
		Date(const usint year, const usint month, const usint day, const char separator);
		Date(const std::string& str, const char separator);
		Date(const Date& date);
		~Date(void);

		Date&	operator=(const Date& date);
		bool	operator<(const Date& date);
		bool	operator<=(const Date& date);
		bool	operator>(const Date& date);
		bool	operator>=(const Date& date);
		bool	operator==(const Date& date);
		bool	operator!=(const Date& date);
		Date&	operator++(void);
		Date	operator++(int);
		Date&	operator--(void);
		Date	operator--(int);

		const std::string	toString(void) const;
		size_t				dateToDays(void) const;
		void				daysToDate(size_t days);

		usint	getYear(void) const;
		usint	getMonth(void) const;
		usint	getDay(void) const;
		char	getSeparator(void) const;

		void	setYear(const usint year);
		void	setMonth(const usint month);
		void	setDay(const usint day);
		void	setSeparator(const char separator);

	private:
		usint	_year;
		usint	_month;
		usint	_day;
		char	_separator;

		static usint	_getActualYear(void);
		static usint	_getActualMonth(void);
		static usint	_getActualDay(void);
		static bool		_isLeapYear(const usint year);
		static usint	_getDayMax(const usint month, const usint year);
		static bool		_isValidSeparator(const char separator);
		static bool		_isValidDate(const usint day, const usint month, usint year);
};

struct	DataRow {
	DataRow(void);
	DataRow(const DataRow& src);
	DataRow(const Date& _date, const double _val);
	~DataRow(void);
	
	Date	date;
	double	val;

	DataRow&	operator=(const DataRow& src);
};

class	DataBase {
	public:
		DataBase(void);
		DataBase(const std::string& csvFile);
		~DataBase(void);

		const std::string&	getCsvFile(void) const;
		const DataRow		searchByDate(const Date& dt);
		const DataRow		searchByValue(const double dbl);

	private:
		std::string				_csvFile;
		std::string				_parse;
		std::ifstream*			_stream;
		std::vector<DataRow>	_list;

		static std::string&	_authCsvFile(const std::string& file);
		void				_validDbFile(void);
		void				_validDbHeaderFile(const std::string& line);
		void				_validDbRawFile(const std::string& line);
		std::ifstream&		_openCsvFile(bool header = false);
		std::ifstream&		_getCsvFile(void);
		void				_closeCsvFile(void);
		bool				_getCache(void);
};

DataBase*	dbInit(const char* dbFile);

#endif
