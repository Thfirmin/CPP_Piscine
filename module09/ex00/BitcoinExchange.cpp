/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:08:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/28 17:01:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Date |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

Date::Date(const std::string& str, const char separator) : _separator(separator) {
	size_t	idx[2] = {0};

	if (!Date::_isValidSeparator(separator)) {
		throw std::invalid_argument("Invalid separator");
	}

	idx[0] = str.find(separator);
	idx[1] = str.rfind(separator);
	if ((str.size() != 10) || (idx[0] == std::string::npos) || (idx[1] == idx[0])) {
		throw std::logic_error("Invalid date format");
	}
	this->_year = atoi(str.substr(0, idx[0]).c_str());
	this->_month = atoi(str.substr((idx[0] + 1), (idx[1] - (idx[0] + 1))).c_str());
	this->_day = atoi(str.substr(idx[1] + 1).c_str());
	if (!Date::_isValidDate(this->_day, this->_month, this->_year)) {
		throw std::invalid_argument("Invalid date");
	}
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
	return (separator == '-');
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

// DataRow |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// CONSTRUCTOR * DESTRUCTOR |===================================================
DataRow::DataRow(void) : date(Date()), val(0.0) {}
DataRow::DataRow(const DataRow& src) { *this = src; }
DataRow::DataRow(const Date& _date, const double _val) : date(_date), val(_val) {}
DataRow::~DataRow(void) {}

// OPERATOR |===================================================================
DataRow& DataRow::operator=(const DataRow& src) {
	this->date = src.date;
	this->val = src.val;
	return (*this);
}

// DataBase |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// CONSTRUCTOR * DESTRUCTOR |===================================================
DataBase::DataBase(void) : _csvFile(DataBase::_authCsvFile(CSV_FILE)), _parse(""), _stream(NULL) {
	this->_validDbFile();
}

DataBase::DataBase(const std::string& csvFile) : _csvFile(DataBase::_authCsvFile(csvFile)), _parse(""), _stream(NULL) {
	this->_validDbFile();
}

DataBase::~DataBase(void) {
	this->_closeCsvFile();
}

// METHOD |=====================================================================
const DataRow	DataBase::searchByDate(const Date& dt) {
	std::vector<DataRow>::iterator	it;
	DataRow							ret;
	bool							file = true;
	
	if  (this->_list.empty() || (this->_list[0].date > dt)) {
		this->_openCsvFile();
		this->_getCache();
	}
	
	ret = this->_list[0];

	if (ret.date > dt)
		throw std::logic_error("Data not found");
	
	while (file) {
		for (it = this->_list.begin(); ((it != this->_list.end()) && file); ++ it) {
			if ((*it).date == dt) {
				ret = *it;
				file = false;
			}
			else if ((*it).date < dt) {
				if ((*it).date > ret.date)
					ret = *it;
			}
			else {
				file = false;
			}
		}
		if (file)
			file = this->_getCache();
	}

	return (ret);
}

const DataRow	DataBase::searchByValue(const double dbl) {
	DataRow	dt;
	
	(void) dbl;
	return (dt);
}

// GETTER * SETTER |============================================================
const std::string&	DataBase::getCsvFile(void) const {
	return (this->_csvFile);
}

// PRIVATE |====================================================================
std::ifstream&	DataBase::_openCsvFile(bool header) {
	std::string	junk;
	
	if (this->_stream) {
		this->_closeCsvFile();
		this->_stream = NULL;
	}
	this->_stream =  new std::ifstream(this->_csvFile.c_str());
	if (!this->_stream || !this->_stream->is_open()) {
		throw std::logic_error("File can't be open");
	}
	if (!header)
		std::getline(*this->_stream, junk);
	return (*this->_stream);
}

void	DataBase::_closeCsvFile(void) {
	if (!this->_stream) {
		return ;
	}
	this->_stream->close();
	delete this->_stream;
	this->_stream = NULL;
}

std::string&	DataBase::_authCsvFile(const std::string& file) {
	if (file.empty())
		throw std::logic_error("Void csv file name");
	size_t	idx = file.rfind(".");
	if ((idx == std::string::npos) || (file.compare(idx, 5, ".csv")))
		throw std::logic_error("Invalid file format");
	if (access(file.c_str(), F_OK | R_OK) < 0)
		throw std::logic_error(strerror(errno));
	return (const_cast<std::string&>(file));
}

void	DataBase::_validDbFile(void) {
	std::ifstream&	file = this->_openCsvFile(true);
	std::string		line;

	std::getline(file, line);
	this->_validDbHeaderFile(line);
	while (std::getline(file, line)) {
		this->_validDbRawFile(line);
	}
	this->_closeCsvFile();
}

void	DataBase::_validDbHeaderFile(const std::string& line) {
	if (!std::equal(line.begin(), (line.begin() + 4), "date")) {
		this->_closeCsvFile();
		throw std::logic_error("<date> field not found");
	}

	size_t	idx = line.find("exchange_rate");
	if (idx == std::string::npos) {
		this->_closeCsvFile();
		throw std::logic_error("<exchange_rate> field not found");
	}

	this->_parse = line.substr(4, (idx - 4));
	if (line.size() != (this->_parse.size() + 17))
		throw std::logic_error("header too long");	
}

void	DataBase::_validDbRawFile(const std::string& line) {
	size_t					idx = line.find(this->_parse);
	std::string				val;
	std::string::iterator	it;
	bool					sign = false;
	Date					dt;

	if (line.size() < 12)
		throw std::invalid_argument("invalid raw data");
	if (idx == std::string::npos)
		throw std::invalid_argument("raw without split sign");

	dt = Date(line.substr(0, idx), '-');

	val = line.substr((idx + this->_parse.size()));
	it = val.begin();
	while (it != val.end()) {
		if (*it == '.') {
			if (sign || !isdigit(*(it + 1)))
				throw std::invalid_argument("raw value is not a number");
			sign = true;
		}
		else if (!isdigit(*it))
			throw std::invalid_argument("raw value is not a number");
		++ it;
	}

	return ;
}

std::ifstream&	DataBase::_getCsvFile(void) {
	return (*this->_stream);
}

bool	DataBase::_getCache(void) {
	std::ifstream&	file = this->_getCsvFile();
	size_t			size = 0;
	std::string		line;
	DataRow			dr;

	this->_list.clear();
	while (std::getline(file, line) && (size < MAX_BLOCK_SIZE)) {
		dr.date = Date(line.substr(0, line.find(this->_parse)), '-');
		dr.val = atof(line.substr(line.find(this->_parse) + 1).c_str());
		this->_list.push_back(DataRow(dr));
		size ++;
	}
	if (!size)
		return (false);
	return (true);
}

// EXTERNAL FUNCTIONS |=========================================================
DataBase*	dbInit(const char* dbFile) {
	DataBase*	db = NULL;

	std::cout << std::endl << "[\e[34mINFO\e[0m]: Initializing Database..." << std::endl;

	try {
		if (dbFile)
			db = new DataBase(dbFile);
		else
			db = new DataBase();
		std::cout << "[\e[32mINFO\e[0m]: Database has been initialized!" << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "[\e[31mERROR\e[0m]: " << e.what() << std::endl;
		return (NULL);
	};
	return (db);
}
