/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:55:58 by thfirmin          #+#    #+#             */
/*   Updated: 2024/03/10 05:59:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STD_DATABASE_PATH "asset/database/data.csv"

#include <iostream>
#include <sstream>
#include <iterator>
#include <cctype>
#include "BitcoinExchange.hpp"

static void checkInputValue(const std::string line);

static void checkInputDate(const std::string& line);

static void	checkInputRow(const std::string& line);

static void	readInputFile(const std::string fileName, DataBase* db);

static void	validInFile(const std::string fileName);

static void	BtcLogo(void);

static int	exitProgram(int ret, DataBase ** db);

int	main(int argc, char *argv[])
{
	if ((argc < 2) || (argc > 3))
	{
		std::cerr << "Usage: ./btc <filepath> [<dbFile>]" << std::endl;
		return (exitProgram(1, 0));
	}

	BtcLogo();

	DataBase	*dbPtr = dbInit((argv[2]) ? argv[2] : "asset/database/data.csv");
	if (!dbPtr) {
		return (exitProgram(2, &dbPtr));
	}

	try {
		std::cout << "[\e[34mINFO\e[0m]: Validating input file..." << std::endl;
		validInFile(*(argv + 1));
		std::cout << "[\e[32mINFO\e[0m]: Input file has been validated!" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "[\e[31mERROR\e[0m]: " << e.what() << std::endl;
		return (exitProgram(3, &dbPtr));
	}
	readInputFile(*(argv + 1), dbPtr);
	
	return (exitProgram(0, &dbPtr));
}

static int	exitProgram(int ret, DataBase ** db)
{
	if (db && *db)
	{
		delete *db;
		*db = NULL;
	}
	return (ret);
}

static void	BtcLogo(void)
{
	std::cout << " ______ ______ ______ ______ ______ ______" << std::endl;
	std::cout << "|      \\      \\      \\      \\      \\      \\" << std::endl;
	std::cout << " \\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓" << std::endl;
	std::cout << "         _______  ________  ______" << std::endl;
	std::cout << "        |       \\|        \\/      \\" << std::endl;
	std::cout << "        | ▓▓▓▓▓▓▓\\\\▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓\\" << std::endl;
	std::cout << "        | ▓▓__/ ▓▓  | ▓▓  | ▓▓   \\▓▓" << std::endl;
	std::cout << "        | ▓▓    ▓▓  | ▓▓  | ▓▓" << std::endl;
	std::cout << "        | ▓▓▓▓▓▓▓\\  | ▓▓  | ▓▓   __" << std::endl;
	std::cout << "        | ▓▓__/ ▓▓  | ▓▓  | ▓▓__/  \\" << std::endl;
	std::cout << "        | ▓▓    ▓▓  | ▓▓   \\▓▓    ▓▓" << std::endl;
	std::cout << "         \\▓▓▓▓▓▓▓    \\▓▓    \\▓▓▓▓▓▓" << std::endl;
	std::cout << " ______ ______ ______ ______ ______ ______" << std::endl;
	std::cout << "|      \\      \\      \\      \\      \\      \\" << std::endl;
	std::cout << " \\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓\\▓▓▓▓▓▓" << std::endl;
}

static void	validInFile(const std::string fileName)
{
	std::ifstream	file;
	std::string		line;

	if (fileName.empty())
		throw std::logic_error("Void input file name");
	
	file.open(fileName.c_str());
	if (!file.is_open())
		throw std::logic_error(strerror(errno));

	std::getline(file, line);
	if (line != "date | value")
		throw std::logic_error("Invalid format Data");
	file.close();
}

static void	readInputFile(const std::string fileName, DataBase* db)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;
	Date			date;
	double			val;
	DataRow			data;

(void) db;
	std::cout << "╒════════════════════════════════════════╡" << std::endl;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		try {
			checkInputRow(line);
			checkInputDate(line);
			checkInputValue(line);
			
			date = Date(line.substr(0, line.find(" | ")), '-');
			val = atof(line.substr(line.find(" | ") + 3).c_str());
			data = db->searchByDate(date);
			
			std::cout << "├ " << date.toString() << " => " << val << " = " << val * data.val << std::endl;
		} catch (std::exception& e) {
			std::cerr << "├ Error: " << e.what() << std::endl;
		}
	}
	file.close();
	std::cout << "╘════════════════════════════════════════╡" << std::endl;
}

static void checkInputRow(const std::string& line)
{
	std::stringstream	stream;

	size_t	idx1 = line.find(" | ");
	size_t	idx2 = line.rfind(" | ");

	stream << "Bad input => " << line;
	if ((idx1 == std::string::npos) || (idx1 != idx2))
		throw std::invalid_argument(stream.str());
	if (line.size() < 14)
		throw std::invalid_argument(stream.str());
	return ;
}

static void checkInputDate(const std::string& line)
{
	Date date(line.substr(0, line.find(" | ")), '-');
	return ;
}

static void checkInputValue(const std::string line)
{
	std::string	str = line.substr(line.find(" | ") + 3);
	size_t		idx = 0;
	
	if (str.at(0) == '-')
		throw std::invalid_argument("Value is not a positive number");

	idx = str.find('.');
	idx = (idx == std::string::npos) ? str.size() : idx;
	if ((idx > 5) || (atof(str.c_str()) > 1000))
		throw std::invalid_argument("Value too large a number");

	std::string::iterator it = str.begin();
	if (*it == '+')
		it ++;
	if (!isdigit(*it))
		throw  std::invalid_argument("Value is not a number");
	idx = 0;
	while (it != str.end()) 
	{
		if (*it == '.')
		{
			if (idx || !isdigit(*(it + 1)))
				throw  std::invalid_argument("Value is not a number");
			idx ++;
		}
		else if (!isdigit(*it))
			throw  std::invalid_argument("Value is not a number");
		it ++;
	}
	return ;
}
