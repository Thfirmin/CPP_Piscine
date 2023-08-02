/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:23:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/02 01:40:33 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

/*int main( void ) 
{
    Fixed a(20);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(10.10f);

    std::cout << "------------------------------------" << std::endl;
    std::cout << "Arithmetic Operation: " << std::endl;
    std::cout << "Operator << result: " << a << std::endl;
    std::cout << "Operator + result: " << a + b << std::endl;
    std::cout << "Operator - result: " << a - b << std::endl;
    std::cout << "Operator * result: " << a * b << std::endl;
    std::cout << "Operator / result: " << (a / b) << std::endl;
    std::cout << "Operator  result: " << b << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Max and Min Operation: " << std::endl;
    std::cout << "A value: " << a << std::endl;
    std::cout << "B value: " << b << std::endl;
    std::cout << "Min between A and B result: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max between A and B result: " << Fixed::max( a, b ) << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "-- and ++ Operation: " << std::endl;
    std::cout << "C value: " << c << std::endl;
    std::cout << "++Pre value: " << ++c << std::endl;
    std::cout << "--Pre: " << --c << std::endl;
    std::cout << "C++ value: " << c++ << std::endl;
    std::cout << "C value: " << c << std::endl;
    std::cout << "C-- value: " << c-- << std::endl;
    std::cout << "C value: " << c << std::endl;
    std::cout << "------------------------------------" << std::endl;

    return 0;
}*/
