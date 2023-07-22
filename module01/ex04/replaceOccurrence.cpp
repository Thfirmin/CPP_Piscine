/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceOccurrence.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:05:17 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 00:33:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedFile.struct.hpp"

void	SedFile::replaceOccurrence(SedFile& sedFile, std::string s1, std::string s2) {
	std::string	line;

	while (std::getline(sedFile._fileIn, line)) {
		for (int i = 0; (!s1.empty() && line[i]); i ++) {
			if (!line.compare(i, s1.length(), s1)) {
				line.erase(i, s1.length());
				line.insert(i, s2);
				i += s2.length() - 1;
			}
		}
		sedFile._fileOut << line << std::endl;
	}
	return ;
}
