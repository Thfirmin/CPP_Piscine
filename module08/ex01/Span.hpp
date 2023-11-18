/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:43:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 18:03:53 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>

typedef unsigned int	uint;

class	Span {
	public:
		Span(uint n);
		~Span(void);

		void	addNumber(int nbr);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		void	getList(void);
		uint	getMaxNumber(void) const;

	private:
		std::vector<int>	_list;
		uint				_maxNumber;
		
};

#endif
