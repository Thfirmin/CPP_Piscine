/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 04:43:28 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 05:35:04 by thfirmin         ###   ########.fr       */
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

		void	getList(void);

	private:
		std::vector<int>	_list;
		uint				_maxNumber;
		
};

#endif
