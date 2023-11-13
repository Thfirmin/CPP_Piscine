/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:08:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 19:45:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	double	elem1 = 3.5;
	double	elem2 = 3.6;

	std::cout << "elem1 [" << elem1 << "]" << std::endl;
	std::cout << "elem2 [" << elem2 << "]" << std::endl;
	std::cout << "min: " << min<int>(elem1, elem2) << std::endl; 
	std::cout << "max: " << max<int>(elem1, elem2) << std::endl; 
	std::cout << "swap" << std::endl; 
	swap<>(elem1, elem2);
	std::cout << "elem1 [" << elem1 << "]" << std::endl;
	std::cout << "elem2 [" << elem2 << "]" << std::endl;
	return (0);
}
