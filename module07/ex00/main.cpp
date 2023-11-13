/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:08:07 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 19:47:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main( void )
{
	int	a = 2;
	int	b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}

/*
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
*/
