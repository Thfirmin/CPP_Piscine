/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:44:21 by thfirmin          #+#    #+#             */
/*   Updated: 2024/03/09 16:23:55 by thfirmin         ###   ########.fr       */
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

	std::vector<int> vec = this->_sort();
	std::vector<int>::iterator	end = vec.end();
	int							min = (*(vec.begin() + 1) - *(vec.begin()));
	//std::vector<int>::iterator	first = this->_list.begin();
	//std::vector<int>::iterator	second = this->_list.begin();

	for (std::vector<int>::iterator it = vec.begin(); it != (end - 1); it ++) {
		if ((*(it + 1) - *it) < min)
			min = ((*(it + 1)) - *it);
	}
	return (min);
}

int	Span::longestSpan(void) {
	if (this->_list.size() <= 1) {
		throw std::logic_error("Span need to be filled with more than two elements");
	}

	std::vector<int>::iterator	end = this->_list.end();
	int							min = *(this->_list.begin());
	int							max = 0;

	for (std::vector<int>::iterator it = this->_list.begin(); it != end; it ++)
		if (min > *it)
			min = *it;
	
	for (std::vector<int>::iterator it = this->_list.begin(); it != end; it ++) {
		if ( max < *it)
			max = *it;
	}

	return (max - min);
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) > this->_maxNumber) {
		throw std::logic_error("Size of range is out of max capacity");
	}
	
	this->_list = std::vector<int>(begin, end);
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

std::vector<int>	Span::_sort(void) {
	std::vector<int>			vec = this->_list;
	std::vector<int>::iterator	end = vec.end() - 1;

	for (std::vector<int>::iterator it = vec.begin(); it != end; it ++) {
		for (std::vector<int>::iterator pointer = end; pointer != it; pointer --) {
			if (*pointer < *(pointer - 1)) {
				*pointer = *pointer ^ *(pointer - 1);
				*(pointer - 1) = *pointer ^ *(pointer - 1);
				*pointer = *pointer ^ *(pointer - 1);
			}
		}
	}

	return (vec);
}
