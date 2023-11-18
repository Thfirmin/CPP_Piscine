/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:21 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 18:08:26 by thfirmin         ###   ########.fr       */
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
	int							diff;

	while (it != (end - 1)) {
		diff = *(it + 1) - *it;
		if (off > diff)
			off = diff;
		++ it;
	}
	return (off);
}

int	Span::longestSpan(void) {
	if (this->_list.size() <= 1) {
		throw std::logic_error("Span need to be filled with more than two elements");
	}
	return (*(this->_list.end() - 1) - *this->_list.begin());
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) > this->_maxNumber) {
		throw std::logic_error("Size of range is out of max capacity");
	}
	while (begin != end) {
		this->addNumber(*begin);
		if (begin < end)
			begin ++;
		else
			begin --;
	}
	return ;
}

void	Span::getList(void) {
	std::vector<int>::iterator	end = this->_list.end();

	std::cout << "list (\e[32m" << this->_list.size() << "\e[0m/\e[33m" << this->_maxNumber << "\e[0m): [";
	for (std::vector<int>::iterator it = this->_list.begin(); it != end; ++ it) {
		std::cout << *it << (it != (end - 1) ? ", " : "");
	}
	std::cout << "]" << std::endl;
	return ;
}

uint	Span::getMaxNumber(void) const {
	return (this->_maxNumber);
}
