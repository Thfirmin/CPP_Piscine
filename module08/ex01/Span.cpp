/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 05:55:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Span::Span(uint n) : _maxNumber(n) {
	return ;
}

Span::~Span(void) {
	this->_list.clear();
	return ;
}

// METHOD |=====================================================================
void	Span::addNumber(int nbr) {
	std::vector<int>::iterator	end = this->_list.end();

	if (this->_list.size() == _maxNumber) {
		throw std::logic_error("Maximum capacity has been reached");
	}
	for (std::vector<int>::iterator it = this->_list.begin(); it != end; ++it) {
		if (nbr < *it) {
			this->_list.insert(it, nbr);
			return ;
		}
	}
	this->_list.push_back(nbr);
	return ;
}

int	Span::shortestSpan(void) {
	if (this->_list.size() <= 1) {
		throw std::logic_error("Span need to be filled with more than two elements");
	}

	std::vector<int>::iterator	it = this->_list.begin();
	std::vector<int>::iterator	end = this->_list.end();
	int							off = (*(it + 1) - *it);

	while (it != end) {
		if (off > (*(it + 1) - *it))
			off = (*(it + 1) - *it);
		++ it;
	}
	return (off);
}

int	Span::longestSpan(void) {
	if (this->_list.size() <= 1) {
		throw std::logic_error("Span need to be filled with more than two elements");
	}
	return (*this->_list.end() - *this->_list.begin());
}

void	Span::getList(void) {
	std::vector<int>::iterator	end = this->_list.end();

	std::cout << "list [\e[32m" << this->_list.size() << "\e[0m/\e[33m" << this->_maxNumber << "\e[0m]" << std::endl;
	for (std::vector<int>::iterator it = this->_list.begin(); it != end; ++ it) {
		std::cout << *it << std::endl;
	}
}

