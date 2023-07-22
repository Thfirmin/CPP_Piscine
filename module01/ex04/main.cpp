/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:34:19 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 00:33:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedFile.struct.hpp"

int	main(int argc, char *argv[])
{
	SedFile	sedFile;

	if (argc != 4) {
		std::cerr << "Usage: " << *argv << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (!sedFile.fileIn(argv[1]))
		return 2;
	if (!sedFile.fileOut(SedFile::standardOutName(argv[1])))
		return 2;
	SedFile::replaceOccurrence(sedFile, argv[2], argv[3]);
	return 0;
}
