#ifndef DATE_HPP
# define DATE_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <stdexcept>
# include <ctime>
# include <cstdlib>

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

#endif