/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:12:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 23:16:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <exception>
#include "MutantStack.hpp"


int	main(void)
{
	MutantStack<int>	mts;
	std::stack<int>		stk;

	std::cout << "mts (" << &mts << "): empty: [" << (mts.empty() ? "TRUE" : "FALSE") << "] | size: [" << mts.size() << "]" << std::endl;
	std::cout << "stk (" << &stk << "): empty: [" << (stk.empty() ? "TRUE" : "FALSE") << "] | size: [" << stk.size() << "]" << std::endl;

	std::cout << "           TOP" << std::endl;
	std::cout << "MutantStack | std::Stack" << std::endl;
	for (int i = 0; i < 10; i += 3)
	{
		mts.push(i);
		stk.push(i);
		std::cout << mts.top() << "           | ";
		std::cout << stk.top() << std::endl;
	}

	std::cout << "mts (" << &mts << "): empty: [" << (mts.empty() ? "TRUE" : "FALSE") << "] | size: [" << mts.size() << "]" << std::endl;
	std::cout << "stk (" << &stk << "): empty: [" << (stk.empty() ? "TRUE" : "FALSE") << "] | size: [" << stk.size() << "]" << std::endl;


	std::cout << "           POP" << std::endl;
	std::cout << "MutantStack | std::Stack" << std::endl;
	while (!mts.empty() && !stk.empty())
	{
		std::cout << mts.top() << "           | ";
		std::cout << stk.top() << std::endl;
		mts.pop();
		stk.pop();
	}

	std::cout << "mts (" << &mts << "): empty: [" << (mts.empty() ? "TRUE" : "FALSE") << "] | size: [" << mts.size() << "]" << std::endl;
	std::cout << "stk (" << &stk << "): empty: [" << (stk.empty() ? "TRUE" : "FALSE") << "] | size: [" << stk.size() << "]" << std::endl;


	return (0);
}
