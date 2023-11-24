/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:08:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/23 19:42:59 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
// BitcoinExchange |++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

// Method |=====================================================================
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
	std::ifstream&	file = this->openCsvFile();
	std::string		line;

	std::getline(file, line);
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
	
	this->_closeCsvFile();
}

// GETTER * SETTER |============================================================
const std::string&	DataBase::getCsvFile(void) const {
	return (this->_csvFile);
}

std::ifstream&	DataBase::openCsvFile(void) {
	if (this->_stream) {
		this->_closeCsvFile();
	}
	this->_stream =  new std::ifstream(this->_csvFile.c_str());
	if (!this->_stream || !this->_stream->is_open()) {
		throw std::logic_error("File can't be open");
	}
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

// Date |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// CONSTRUCTOR * DESTRUCTOR |===================================================
Date::Date(void) : _day(1), _month(1), _year(1) {
	this->authDate();
	return ;
}

Date::Date(const int day, const int month, const int year) : _day(day), _month(month), _year(year) {
	this->authDate();
	return ;
}

Date::Date(const std::string& str) {
	this->parseDateString(str);
	this->authDate();
}

Date::Date(const Date& date) {
	*this = date;
	return ;
}

// OPERATOR |===================================================================
Date&	Date::operator=(const Date& date) {
	this->_day = date.getDay();
	this->_month = date.getMonth();
	this->_year = date.getYear();
	this->_split = date.getSplit();
	return (*this);
}

bool	Date::operator<(const Date& date) {
	return (this->dateToDay() < date.dateToDay());
}

bool	Date::operator>(const Date& date) {
	return (this->dateToDay() > date.dateToDay());
}

bool	Date::operator<=(const Date& date) {
	return (this->dateToDay() <= date.dateToDay());
}

bool	Date::operator>=(const Date& date) {
	return (this->dateToDay() >= date.dateToDay());
}

bool	Date::operator==(const Date& date) {
	return (this->dateToDay() == date.dateToDay());
}

bool	Date::operator!=(const Date& date) {
	return (this->dateToDay() != date.dateToDay());
}

Date&	Date::operator++(void) {

	return (*this);
}

Date	Date::operator++(int) {
	return (*this);
}

Date&	Date::operator--(void) {
	return (*this);
}

Date	Date::operator--(void) {
	return (*this);
}

// METHOD |=====================================================================

// GETTER * SETTER |============================================================


