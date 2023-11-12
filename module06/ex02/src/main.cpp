/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:12:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/12 00:49:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpp06.02.hpp"

int	main(void)
{
	Base*	test;

	test = generate();
	std::cout << "test: (" << test << ")" << std::endl;
	identify(test);
	identify(*test);
	delete test;
	return (0);
}
