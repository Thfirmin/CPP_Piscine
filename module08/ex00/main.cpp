/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:39:46 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/15 21:54:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <list>
#include <typeinfo>
#include <cctype>
#include <cstdlib>
#include "easyfind.hpp"

template <typename T>
void	readContainer(const T& container);

template <typename T, typename U>
void	fillContainer(T& container, U* list, int size);

template <typename T>
int	testContainer(T& container, int* list, int size);

void	argsValidation(int argc, char* argv[]);

int	main(int argc, char* argv[])
{
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;
	
	int					size = (argc - 1);
	int					list[size] = {0};
	int					ret = 0;

	try
	{
		argsValidation(argc, argv);
		for (int i = 0; i < size; ++ i)
			list[i] = atoi(*(argv + i + 1));
	}
	catch (std::exception& e)
	{
		std::cerr << ((*argv) + 2) << ": " << e.what() << std::endl;
		return (1);
	};

	ret = testContainer(vec, list, size);
	std::cout << "Return: " << ret << std::endl;

	ret = testContainer(deq, list, size);
	std::cout << "Return: " << ret << std::endl;

	ret = testContainer(lst, list, size);
	std::cout << "Return: " << ret << std::endl;
	return (0);
}

void	argsValidation(int argc, char* argv[])
{
	std::string	msg;
	char		*str;

	if (argc < 3) {
		msg = "usage: ";
		msg += *argv;
		msg += " <numberToFInd> <numberList...>";
		throw std::logic_error(msg.c_str());
	}
	for (int i = 1; i < argc; ++ i)
	{
		str = *(argv + i);
		if ((*str == '-') || (*str == '+'))
			++ str;
		if (!*str)
		{
			msg = "Invalid 'void' argument";
			throw std::logic_error(msg.c_str());
		}
		for (int j = 0; *(str + j); ++ j)
		{
			if (!isdigit(*(str + j)))
			{
				msg = "Just 'int' type as argument";
				throw std::logic_error(msg.c_str());
			}
		}
	}
	return ;
}

template <typename T>
int	testContainer(T& container, int* list, int size)
{
	int	ret = 0;

	std::cout << "[ " << typeid(container).name() << " ]" << std::endl;
	fillContainer(container, (list + 1), (size - 1));
	readContainer(container);
	try
	{
		ret = easyfind(container, list[0]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	};
	return (ret);
}

template <typename T, typename U>
void	fillContainer(T& container, U* list, int size)
{
	for (int i = 0; i < size; ++ i)
		container.push_back(list[i]);
}

template <typename T>
void	readContainer(const T& container)
{
	typename T::const_iterator	end = container.end();

	std::cout << "(" << container.size() << ") [";
	for (typename T::const_iterator it = container.begin(); it != end; ++ it)
	{
		if (it != container.begin()) {
			std::cout << ", ";
		}
		std::cout << *it;
	}
	std::cout << "]" << std::endl;
}
