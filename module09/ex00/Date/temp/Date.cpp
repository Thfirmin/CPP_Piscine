/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:55:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/23 23:47:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

// ATTRIBUTE |==================================================================

// CONSTRUCTOR * DESTRUCTOR |===================================================
Date::Date(void) : _day(Date::_getActualDay()), _month(Date::_getActualMonth()), _year(Date::_getActualYear()), _separator('-') {
	return ;
}

Date::Date(short int day, short int month, short int year, char separator) : _day(day), _month(month), _year(year), _separator(separator) {
	if (!Date::_isValidDate(this->_day, this->_month, this->_year))
		throw std::invalid_argument("Error: invalid date");
	return ;
}

Date::Date(const std::string &date, char separator) : _separator(separator) {
	size_t	separatorPos;

	if (!Date::_isValidSeparator(this->_separator))
		throw std::invalid_argument("Error: invalid separator");

	separatorPos = date.find(this->_separator);
	if (separatorPos == std::string::npos)
		throw std::invalid_argument("Error: invalid date");

	this->_year = atoi(date.substr(0, separatorPos));
	date.erase(0, separatorPos + 1);
	separatorPos = date.find(this->_separator);
	if (separatorPos == std::string::npos)
		throw std::invalid_argument("Error: invalid date");
	this->_month = std::stoi(date.substr(0, separatorPos));
	date.erase(0, separatorPos + 1);
	this->_year = atoi(date);
	if (!Date::_isValidDate(this->_day, this->_month, this->_year))
		throw std::invalid_argument("Error: invalid date");
	return ;
}

Date::Date(Date const &src) {
	*this = src;
	return ;
}

Date::~Date(void) {
	return ;
}

// OPERATOR |===================================================================

Date	&Date::operator=(Date const &src) {
	this->_day = src.getDay();
	this->_month = src.getMonth();
	this->_year = src.getYear();
	this->_separator = src.getSeparator();
	return (*this);
}

bool	Date::operator==(Date const &src) const {
	return ((this->_day == src.getDay()) && (this->_month == src.getMonth()) && (this->_year == src.getYear()));
}

bool	Date::operator!=(Date const &src) const {
	return ((this->_day != src.getDay()) || (this->_month != src.getMonth()) || (this->_year != src.getYear()));
}

bool	Date::operator<(Date const &src) const {
	return (this->dateToDays() < src.dateToDays());
}

bool	Date::operator<=(Date const &src) const {
	return (this->dateToDays() <= src.dateToDays());
}

bool	Date::operator>(Date const &src) const {
	return (this->dateToDays() > src.dateToDays());
}

bool	Date::operator>=(Date const &src) const {
	return (this->dateToDays() >= src.dateToDays());
}

Date&	Date::operator++(void) {
	this->daysToDate(this->dateToDays() + 1);
	return (*this);
}

Date	Date::operator++(int) {
	Date	tmp(*this);

	this->daysToDate(this->dateToDays() + 1);
	return (tmp);
}

Date&	Date::operator--(void) {
	this->daysToDate(this->dateToDays() - 1);
	return (*this);
}

Date	Date::operator--(int) {
	Date	tmp(*this);

	this->daysToDate(this->dateToDays() - 1);
	return (tmp);
}

// PUBLIC METHOD |==============================================================

size_t	Date::dateToDays(void) const {
	size_t	days;
	short int	year;

	days = 0;
	year = 1970;
	while (year < this->_year)
	{
		days += Date::_isLeapYear(year) ? 366 : 365;
		year++;
	}
	while (year > this->_year)
	{
		days -= Date::_isLeapYear(year) ? 366 : 365;
		year--;
	}
	for (short int month = 1; month < this->_month; month++)
		days += Date::_getDayMax(month, this->_year);
	days += this->_day;
	return (days);
}

void	Date::daysToDate(size_t days) {
	short int	year;

	year = 1970;
	while (days > (Date::_isLeapYear(year) ? 366 : 365))
	{
		days -= Date::_isLeapYear(year) ? 366 : 365;
		year++;
	}
	while (days < (Date::_isLeapYear(year) ? 366 : 365))
	{
		days += Date::_isLeapYear(year) ? 366 : 365;
		year--;
	}
	this->_year = year;
	this->_month = 1;
	while (days > Date::_getDayMax(this->_month, this->_year))
	{
		days -= Date::_getDayMax(this->_month, this->_year);
		this->_month++;
	}
	this->_day = days;
}

// PRIVATE METHOD |=============================================================

// STATIC METHOD |==============================================================

short int	Date::_getDayMax(short int month, short int year) {
	short int	dayMax;

	if (month == 2)
		dayMax = Date::_isLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		dayMax = 30;
	else
		dayMax = 31;
	return (dayMax);
}

bool		Date::_isLeapYear(short int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool		Date::_isValidDate(short int day, short int month, short int year) {
	return (((day > 0) && (day <= Date::_getDayMax(month, year))) && ((month > 0) && (month <= 12)) && (year > 0));
}

bool		Date::_isValidSeparator(char separator) {
	return (separator == '/' || separator == '-' || separator == '.');
}

short int	Date::_getActualDay(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_mday);
}

short int	Date::_getActualMonth(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_mon + 1);
}

short int	Date::_getActualYear(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_year + 1900);
}

// GETTER |=====================================================================
short int	Date::getDay(void) const {
	return (this->_day);
}

short int	Date::getMonth(void) const {
	return (this->_month);
}

short int	Date::getYear(void) const {
	return (this->_year);
}

char		Date::getSeparator(void) const {
	return (this->_separator);
}

const std::string	Date::toString(void) const {
	std::string	date;

	date = std::to_string(this->_day) + this->_separator + std::to_string(this->_month) + this->_separator + std::to_string(this->_year);
	return (date);
}

// SETTER |=====================================================================
void	Date::setDay(short int day) {
	if (Date::_isValidDate(day, this->_month, this->_year))
		this->_day = day;
	else
		std::cerr << "Error: invalid day" << std::endl;
}

void	Date::setMonth(short int month) {
	if (Date::_isValidDate(this->_day, month, this->_year))
		this->_month = month;
	else
		std::cerr << "Error: invalid month" << std::endl;
}

void	Date::setYear(short int year) {
	if (Date::_isValidDate(this->_day, this->_month, year))
		this->_year = year;
	else
		std::cerr << "Error: invalid year" << std::endl;
}

void	Date::setSeparator(char separator) {
	if (Date::_isValidSeparator(separator))
		this->_separator = separator;
	else
		std::cerr << "Error: invalid separator" << std::endl;
}

// EXTERNAL FUNCTION |==========================================================
