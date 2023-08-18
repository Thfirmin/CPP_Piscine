/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedFile.struct.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:42:08 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/18 00:46:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedFile.struct.hpp"

// Constructors * Destructors
SedFile::SedFile(void) {
	return ;
}

SedFile::~SedFile(void) {
	this->_fileIn.close();
	this->_fileOut.close();
	return ;
}

// Statics
const std::string	SedFile::standardOutName(std::string fileName) {
	return fileName + ".replace";
}

// Getters * Setters
bool	SedFile::fileIn(const std::string& fileName) {
	if (fileName.empty()) {
		errno = ENOENT;
		perror("''");
		return false;
	}
	this->_fileIn.open(fileName.c_str());
	if (!this->_fileIn.is_open()) {
		perror(fileName.c_str());
		return false;
	}
	return true;
}

bool	SedFile::fileOut(const std::string& fileName) {
	if (fileName.empty()) {
		errno = ENOENT;
		perror("''");
		return false;
	}
	this->_fileOut.open(fileName.c_str());
	if (!this->_fileOut.is_open()) {
		perror(fileName.c_str());
		return false;
	}
	return true;
}
