/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:12:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/22 23:23:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include <exception>
#include <typeinfo>
#include "MutantStack.hpp"


int	main(void)
{
	MutantStack<int>	mts;
	std::stack<int>		stk;

	std::cout << "mts (" << &mts << "): empty: [" << (mts.empty() ? "TRUE" : "FALSE") << "] | size: [" << mts.size() << "]" << std::endl;
	std::cout << "stk (" << &stk << "): empty: [" << (stk.empty() ? "TRUE" : "FALSE") << "] | size: [" << stk.size() << "]" << std::endl;

	for (int i = 0; i < 50; i += 5)
		mts.push(i);

	MutantStack<int>::iterator	from = mts.begin();
	MutantStack<int>::iterator	until = mts.end();

	for (MutantStack<int>::iterator it = from; it != until; it++) {
		std::cout << "it: " << *it << std::endl;
	}
	return (0);
}
