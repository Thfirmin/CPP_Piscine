/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:24:49 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/05 22:55:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <ctime>
# include <deque>
# include <vector>
# include <iterator>
# include <typeinfo>

class	PmergeMe {
	public:
		static void	pmergeMe(int argc, char **argv);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe(void);

		static std::deque<int>	_list;

		PmergeMe&	operator=(const PmergeMe& src);

		static int	_toInt(const std::string& str);

		template <class Dock>
		static void	_fill(Dock& dock, int argc, char **argv);

		template <class Dock>
		static std::string	_toString(Dock& dock);

		template <class Dock>
		static void	_fordJohnsonSort(Dock& dock, class Dock::iterator start, class Dock::iterator end);

		template <class Dock>
		static std::string	_start(Dock& dock, int argc, char **argv);
};

// TEMPLATE IMPLEMENTATION
template <class Dock>
void	PmergeMe::_fill(Dock& dock, int argc, char **argv) {
	for (int i = 0; i < argc; i ++) {
		dock.push_back(PmergeMe::_toInt(*(argv + i)));
	}
}

template <class Dock>
std::string	PmergeMe::_toString(Dock& dock) {
	std::stringstream		stream;
	class Dock::iterator	end = dock.end();

	if (dock.size() > 20) {
		end = (dock.begin() + 5);
	}

	for (class Dock::iterator it = dock.begin(); it != end; it ++)
		stream << *it << (it + 1 != end ? " " : "");

	if (dock.size() > 20)
		stream << " [...]";

	return (stream.str());
}

template <class Dock>
void	PmergeMe::_fordJohnsonSort(Dock& dock, class Dock::iterator start, class Dock::iterator end) {
	int	aux = 0;
	
	if (start + 1 != end) {
		int	dist = std::distance(start, end) / 2;
		PmergeMe::_fordJohnsonSort(dock, start, end - dist);
		PmergeMe::_fordJohnsonSort(dock, start + dist, end);
	}

	for (class Dock::iterator it = (start + 1); it != end; it ++) {
		for (class Dock::iterator it2 = it; it2 != start; it2 --) {
			if (*it2 < *(it2 - 1)) {
				aux = *it2;
				*it2 = *(it2 - 1);
				*(it2 - 1) = aux;
			}
			else
				break ;
		}
	}
}

template <class Dock>
std::string	PmergeMe::_start(Dock& dock, int argc, char **argv) {
	clock_t	clk;
	std::stringstream	stream;

	clk = clock();
	PmergeMe::_fill(dock, argc, argv);
	PmergeMe::_fordJohnsonSort(dock, dock.begin(), dock.end());
	clk = clock() - clk;
	stream << "Time to process a range of " << dock.size() << " elements with std::" << typeid(dock).name() << " : " << std::fixed << std::setprecision(8) << (static_cast<double>(clk) / CLOCKS_PER_SEC) << " " << "us" << std::endl;
	return (stream.str());
}

#endif
