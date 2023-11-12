/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:49:20 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/12 00:49:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// CONSTRUCTOR * DESTRUCTOR |===================================================
Base::~Base(void) {
	return ;
}

// EXTERNAL FUNCTIONS |=========================================================
Base*	generate(void) {
	static char	seed;
	short int	random;
	Base*		inst;

	if (!seed) {
		srand(time(NULL));
		seed ++;
	}
	random = (rand() % 3);
	switch (random) {
		case (1):
			inst = new A;
			std::cout << "generate A..." << std::endl;
			break ;
		case (2):
			inst = new B;
			std::cout << "generate B..." << std::endl;
			break ;
		default:
			inst = new C;
			std::cout << "generate C..." << std::endl;
			break ;
	};
	return (inst);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "(\e[33m" << p << "\e[0m): \e[32mA\e[0m" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "(\e[33m" << p << "\e[0m): \e[32mB\e[0m" << std::endl;
	}
	else {
		std::cout << "(\e[33m" << p << "\e[0m): \e[32mC\e[0m" << std::endl;
	} 
	return ;
}

void	identify(Base& p) {
	try {
		A&	APtr = dynamic_cast<A&>(p);
		std::cout << "(\e[33m" << &APtr << "\e[0m): \e[32mA\e[0m" << std::endl;
		return ;
	}
	catch (std::exception& e) {};
	try {
		B&	BPtr = dynamic_cast<B&>(p);
		std::cout << "(\e[33m" << &BPtr << "\e[0m): \e[32mB\e[0m" << std::endl;
		return ;
	}
	catch (std::exception& e) {};
	std::cout << "(\e[33m" << &p << "\e[0m): \e[32mC\e[0m" << std::endl;
	return ;
}
