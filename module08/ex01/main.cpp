/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:07:01 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 05:56:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int	main(void)
{
	Span	spn(5);

	spn.addNumber(4);
	spn.addNumber(13);
	spn.addNumber(1);
	spn.addNumber(8);
	spn.addNumber(8);

	spn.getList();
	std::cout << "longest: " << spn.longestSpan() << std::endl;
	std::cout << "shortest: " << spn.shortestSpan() << std::endl;
	return (0);
}
