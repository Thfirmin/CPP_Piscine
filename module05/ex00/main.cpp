/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:54:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 23:46:30 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	inst("thino", 42);
	std::cout << "Hello, World! " << inst.getName() << " " << inst.getGrade() << std::endl;
	return (0);
}
