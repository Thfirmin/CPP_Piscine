/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedFile.struct.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:40:10 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 16:27:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDFILE_STRUCT_HPP
# define SEDFILE_STRUCT_HPP

# include <iostream>
# include <fstream>
# include <string>

/*
 * Variables
 * Constructors * Destructors
 * Methods
 * Statics
 * Getters * Setters
 */

struct	SedFile {
	private:
		// Variables
		std::ifstream	_fileIn;
		std::ofstream	_fileOut;

	public:
		// Constructors * Destructors
		SedFile(void);
		~SedFile(void);

		// Statics
		static const std::string	standardOutName(std::string fileName);
		static void					replaceOccurrence(SedFile& sedFile, std::string s1, std::string s2);

		// Getters * Setters
		bool	fileIn(const std::string fileName);
		bool	fileOut(const std::string fileName);
};

#endif
