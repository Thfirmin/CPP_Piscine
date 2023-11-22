/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:12:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/20 20:26:47 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <exception>
#include "MutantStack.hpp"


int	main(void)
{
	MutantStack<int>	mts;
	std::stack<int>		stk;

	std::cout << "mts (" << &mts << "): empty: [" << (mts.empty() ? "TRUE" : "FALSE") << "] | size: [" << mts.size() << "]" << std::endl;
	std::cout << "stk (" << &stk << "): empty: [" << (stk.empty() ? "TRUE" : "FALSE") << "] | size: [" << stk.size() << "]" << std::endl;


	return (0);
	}
