/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:55:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/23 18:27:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <iterator>
#include <cctype>
#include "BitcoinExchange.hpp"

static void	checkInputRow(std::string& line);

static void	readInputFile(const std::string fileName);

static void	validInFile(const std::string fileName);

static void	BtcLogo(void);

int	main(int argc, char *argv[])
{
	if ((argc < 2) || (argc > 3))
	{
		std::cerr << "Usage: ./btc <filepath> [<dbFile>]" << std::endl;
		return (1);
	}

	BtcLogo();

	DataBase	*dbPtr = dbInit(*(argv + 2));
	if (!dbPtr) {
		return (2);
	}

	try {
		std::cout << "[\e[34mINFO\e[0m]: Validating input file..." << std::endl;
		validInFile(*(argv + 1));
		std::cout << "[\e[32mINFO\e[0m]: Input file has been validated!" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "[\e[31mERROR\e[0m]: " << e.what() << std::endl;
		delete dbPtr;
		return (3);
	}
	std::cout << "╒════════════════════════════════════════╡" << std::endl;
	readInputFile(*(argv + 1));
	std::cout << "╘════════════════════════════════════════╡" << std::endl;
	

	delete dbPtr;
	return (0);
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

static void	readInputFile(const std::string fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		try {
			checkInputRow(line);
			std::cout << "├ " << line << std::endl;
		} catch (std::exception& e) {
			std::cerr << "├ Error: " << e.what() << std::endl;
		}
	}
	file.close();
}

static void	checkInputRow(std::string& line)
{
	std::stringstream	stream;
	std::string			str;
	size_t				idx;
	int					date[3];
	int					aux;

	idx = line.find(" | ");
	if (idx == std::string::npos) {
		stream << "bad input => " << line;
		throw std::logic_error(stream.str());
	}

	str = line.substr(0, idx);
	if ((str.size() != 10) || (str[4] != '-') || (str[7] != '-'))
		throw std::logic_error("incorrect date format");

	for (std::string::iterator it = line.begin(); it != (line.begin() + idx); it ++)
		if (!isdigit(*it))
			if ((std::distance(line.begin(), it) != 4) && (std::distance(line.begin(), it) != 7))
				throw std::logic_error("date consists of numbers");
	
	date[0] = atoi(line.substr(0, 4).c_str());
	date[1] = atoi(line.substr(5, 2).c_str());
	date[2] = atoi(line.substr(8, 2).c_str());
	if ((date[0] > 2023) || (!date[1] || (date[1] > 12)) || (!date[2] || (date[2] > 31)))
		throw std::logic_error("non-existent date");

	if ((date[2] == 1) || (date[2] == 3) || (date[2] == 5) || (date[2] == 7) || (date[2] == 8) || (date[2] == 10) || (date[2] == 12))
		aux = 31;
	else if ((date[2] == 4) || (date[2] == 6) || (date[2] == 9) || (date[2] == 11))
		aux = 30;
	else {
		aux = 28;
		if (!(date[0] % 4) && ((date[0] % 100) || !(date[0] % 400)))
			aux ++;
	}
	if (date[2] > date[0])
		throw std::logic_error("non-existent date");

	str = line.substr(idx + 3);
}

