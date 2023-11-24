/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:47:18 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/24 00:22:19 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Date.hpp"

int	main(void)
{
	Date	date;
	size_t	days;

	std::cout << date.toString() << std::endl;
	try
	{
		date.setYear(2);
		date.setMonth(12);
		date.setDay(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	};
	days = date.dateToDays();
	std::cout << date.toString() << "(" << days << ")" << std::endl;
	days += 2 + 31 + 365 + 28;
	date.daysToDate(days);
	std::cout << days << "=> (" << date.toString() << ")" << std::endl;
	date++;
	std::cout << days << "=> (" << date.toString() << ")" << std::endl;
	return (0);
}