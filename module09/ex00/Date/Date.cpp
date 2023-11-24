#include "Date.hpp"

// STATIC ATTRIBUTE |==========================================================

// CONSTRUCTOR * DESTRUCTOR |==================================================
Date::Date(void) : _year(Date::_getActualYear()), _month(Date::_getActualMonth()), _day(Date::_getActualDay()), _separator('-') {
	if (!Date::_isValidDate(this->_day, this->_month, this->_year))
		throw std::invalid_argument("Invalid date");
	return ;
}

Date::Date(const usint year, const usint month, const usint day, const char separator) : _year(year), _month(month), _day(day), _separator(separator) {
	if (!Date::_isValidDate(this->_day, this->_month, this->_year))
		throw std::invalid_argument("Invalid date");
	return ;
}

Date::Date(const Date& date) {
	*this = date;
	return ;
}

Date::~Date(void) {
	return ;
}

// OPERATOR |==================================================================
Date&	Date::operator=(const Date& date) {
	this->_year = date.getYear();
	this->_month = date.getMonth();
	this->_day = date.getDay();
	this->_separator = date.getSeparator();
	return (*this);
}

bool	Date::operator<(const Date& date) {
	return (this->dateToDays() < date.dateToDays());
}

bool	Date::operator<=(const Date& date) {
	return (this->dateToDays() <= date.dateToDays());
}

bool	Date::operator>(const Date& date) {
	return (this->dateToDays() > date.dateToDays());
}

bool	Date::operator>=(const Date& date) {
	return (this->dateToDays() >= date.dateToDays());
}

bool	Date::operator==(const Date& date) {
	return (this->dateToDays() == date.dateToDays());
}

bool	Date::operator!=(const Date& date) {
	return (this->dateToDays() != date.dateToDays());
}

Date&	Date::operator++(void) {
	this->daysToDate(this->dateToDays() + 1);
	return (*this);
}

Date	Date::operator++(int) {
	Date	date(*this);
	this->daysToDate(this->dateToDays() + 1);
	return (date);
}

Date&	Date::operator--(void) {
	this->daysToDate(this->dateToDays() - 1);
	return (*this);
}

Date	Date::operator--(int) {
	Date	date(*this);
	this->daysToDate(this->dateToDays() - 1);
	return (date);
}

// PUBLIC METHOD |=============================================================
const std::string	Date::toString(void) const {
	std::stringstream	stream;

	stream << std::setfill('0') << std::setw(4) << this->_year;
	stream << this->_separator;
	stream << std::setfill('0') << std::setw(2) << this->_month;
	stream << this->_separator;
	stream << std::setfill('0') << std::setw(2) << this->_day;
	return (std::string(stream.str()));
}

size_t	Date::dateToDays(void) const {
	size_t	days = 0;
	usint	year = 0;

	while (year < this->_year) {
		if ((year + 4) < this->_year) {
			days += Date::_isLeapYear(year) ? 366 + (3 * 365) : (4 * 365);
			year += 4;
		}
		else {
			days += Date::_isLeapYear(year) ? 366 : 365;
			year ++;
		}
	}
	
	for (usint month = 1; month < this->_month; month ++) {
		days += Date::_getDayMax(month, this->_year);
	}
	
	days += this->_day - 1;

	return (days);
}

void	Date::daysToDate(size_t	days) {
	usint	year = 0;
	usint	month = 1;

	while (days >= 365) {
		if (days > 1461) {
			days -= Date::_isLeapYear(year) ? 1461 : 1460;
			year += 4;
		}
		else {
			days -= Date::_isLeapYear(year) ? 366 : 365;
			year ++;
		}
	}
	this->_year = year;
	while (days >= Date::_getDayMax(month, year)) {
		days -= Date::_getDayMax(month, year);
		month ++;
	}
	this->_month = month;
	this->_day = days + 1;
	return ;
}

// STATIC METHOD |=============================================================

// PRIVATE METHOD |============================================================
usint	Date::_getActualYear(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_year + 1900);
}

usint	Date::_getActualMonth(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_mon + 1);
}

usint	Date::_getActualDay(void) {
	time_t		today;
	struct tm	*actualDate;

	time(&today);
	actualDate = localtime(&today);
	return (actualDate->tm_mday);
}

bool	Date::_isLeapYear(const usint year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

usint	Date::_getDayMax(const usint month, const usint year) {
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		return (30);
	else if (month == 2)
		return (Date::_isLeapYear(year) ? 29 : 28);
	else
		return (31);
}

bool	Date::_isValidSeparator(const char separator) {
	return (separator == '/' || separator == '-' || separator == '.');
}

bool	Date::_isValidDate(const usint day, const usint month, const usint year) {
	return (((day > 0) && (day <= Date::_getDayMax(month, year))) && ((month > 0) && (month <= 12)) && (year > 0));
}

// GETTER |====================================================================
usint	Date::getYear(void) const {
	return (this->_year);
}

usint	Date::getMonth(void) const {
	return (this->_month);
}

usint	Date::getDay(void) const {
	return (this->_day);
}

char	Date::getSeparator(void) const {
	return (this->_separator);
}

// SETTER |====================================================================
void	Date::setYear(const usint year) {
	if (!Date::_isValidDate(this->_day, this->_month, year))
		throw std::invalid_argument("Invalid year");
	this->_year = year;
	return ;
}

void	Date::setMonth(const usint month) {
	if (!Date::_isValidDate(this->_day, month, this->_year))
		throw std::invalid_argument("Invalid month");
	this->_month = month;
	return ;
}

void	Date::setDay(const usint day) {
	if (!Date::_isValidDate(day, this->_month, this->_year))
		throw std::invalid_argument("Invalid day");
	this->_day = day;
	return ;
}

void	Date::setSeparator(const char separator) {
	if (!Date::_isValidSeparator(separator))
		throw std::invalid_argument("Invalid separator");
	this->_separator = separator;
	return ;
}
