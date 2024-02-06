/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:25:40 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/05 22:33:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <stdexcept>
#include <cstdlib>

// ATTRIBUTES |=================================================================
std::deque<int>	PmergeMe::_list;

// CONSTRUCTOR * DESTRUCTOR |===================================================

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

	PmergeMe::~PmergeMe(void) {}

// OPERATORS |==================================================================

PmergeMe&	PmergeMe::operator=(const PmergeMe& src) {
	(void) src;
	return *this;
}

// METHODS |====================================================================
void	PmergeMe::pmergeMe(int argc, char **argv) {
	std::deque<int>		dq;
	std::vector<int>	vc;

	PmergeMe::_fill(PmergeMe::_list, argc, argv);
	std::cout << "Before: " << PmergeMe::_toString(PmergeMe::_list) << std::endl;
	PmergeMe::_fordJohnsonSort(PmergeMe::_list, PmergeMe::_list.begin(), PmergeMe::_list.end());
	std::cout << "After:  " << PmergeMe::_toString(PmergeMe::_list) << std::endl;
	std::cout << PmergeMe::_start(dq, argc, argv);
	std::cout << PmergeMe::_start(vc, argc, argv);
}

int	PmergeMe::_toInt(const std::string& str) {
	long int aux;
	std::string::const_iterator	it = str.begin();

	if (str.empty() || str.length() > 10) {
		throw std::logic_error("Invalid numeric argument");
	}

	for (std::string::const_iterator end = str.end(); it != end; it ++) {
		if (it == str.begin()) {
			if ((*it < '0' || *it > '9') && *it != '+')
				throw std::logic_error("Invalid numeric argument");
			continue ;
		}
		if (*it < '0' || *it > '9')
			throw std::logic_error("Invalid numeric argument");
	}

	aux = atoi(str.c_str());

	if (aux < 0 || aux > 2147483647) {
		throw std::logic_error("Invalid numeric argument");
	}

	return (aux);
}
