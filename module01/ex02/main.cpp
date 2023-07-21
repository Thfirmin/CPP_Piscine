/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:46:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 22:55:55 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Mem addr of str: " << &str << std::endl;
	std::cout << "Mem addr of ptr: " << stringPTR << std::endl;
	std::cout << "Mem addr of ref: " << &stringREF << std::endl;

	std::cout << "Content of str [" << str << "]" << std::endl;
	std::cout << "Content of ptr [" << *stringPTR << "]" << std::endl;
	std::cout << "Content of ref [" << stringREF << "]" << std::endl;
	return 0;
}
