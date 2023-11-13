/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:50:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 20:57:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void	func(T& i) {
	i ++;
}

int	main(void)
{
	float	arr[] = {41.1, 42.2, 43.3, 45.4, 44.5};

	for (int i = 0; i < 5; i ++)
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
	iter(arr, 5, func);
	std::cout << "--------------------------" << std::endl;
	for (int i = 0; i < 5; i ++)
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
	return (0);
}
