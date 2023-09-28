/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:19:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/27 22:18:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat src2("thino", 150);

		Form	src("sheet", 42, 42, false);

		std::cout << std::endl << "| BEFORE |" << std::endl << src2 << std::endl << src << std::endl;

		src2.signForm(src);
		
		std::cout << std::endl << "| AFTER |" << std::endl << src2 << std::endl << src << std::endl;

	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}
