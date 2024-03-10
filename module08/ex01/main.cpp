/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:07:01 by thfirmin          #+#    #+#             */
/*   Updated: 2024/03/09 15:02:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>
#include "Span.hpp"

void	valid_arguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	try
	{
		valid_arguments(argc - 1, argv + 1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	};

	Span				sp = Span(argc - 1);
	std::vector<int>	list;

	for (int i = 1; i < argc; i ++)
		list.push_back(atoi(*(argv + i)));

	sp.fillSpan(list.begin(), list.end());
	sp.getList();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

void	valid_arguments(int argc, char *argv[])
{
	char	*str;

	if (argc < 2)
		throw std::logic_error("Must be two or more arguments");
	for (int i = 0; i < argc; i ++)
	{
		str = *(argv + i);
		if ((*str == '-') || (*str == '+'))
			str ++;
		if (!*str)
			throw std::logic_error("Invalid void Arguments");
		for (int j = 0; *(str + j); j ++)
		{
			if (!isdigit(*(str + j)))
				throw std::logic_error("Argument need to be int type");
		}
	}
}
