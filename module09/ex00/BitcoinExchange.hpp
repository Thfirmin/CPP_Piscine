/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:07:15 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/24 16:28:53 by thfirmin         ###   ########.fr       */
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

DataBase*	dbInit(const char* dbFile);

#endif
