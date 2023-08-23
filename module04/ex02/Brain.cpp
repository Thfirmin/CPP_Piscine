/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:08:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/23 15:42:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Brain::Brain(void) {
	std::cout << "\e[32mBrain\e[0m [\e[35m" << this << "\e[0m]: Default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& src) {
	*this = src;
	std::cout << "\e[32mBrain\e[0m [\e[35m" << this << "\e[0m]: Copy constructor called" << std::endl;
	return ;
}

Brain::~Brain(void){
	std::cout << "\e[31mBrain\e[0m [\e[35m" << this << "\e[0m]: Destructor called" << std::endl;
	return ;
}

// METHOD |=====================================================================

// OPERATOR |===================================================================
Brain&	Brain::operator=(const Brain& sign) {
	for (int i = 0; i < BRAIN_MAX_IDEAS; i ++)
		this->setIdeas(i, sign.getIdeas(i));
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Brain& brain) {
	out << "Ideas [" << &brain << "] {" << std::endl;
	for (int i = 0; brain.getIdeas(i).length(); i ++)
		out << "\tIdea[" << i << "]: \"" << brain.getIdeas(i) << "\"" << std::endl;
	out	<< "}" << std::endl;
	return out;
}

// GETTER * SETTER |============================================================
const std::string&	Brain::getIdeas(int index) const {
	return this->ideas[index];
}

void	Brain::setIdeas(int index, const std::string& _idea) {
	this->ideas[index] = _idea;
	return ;
}
