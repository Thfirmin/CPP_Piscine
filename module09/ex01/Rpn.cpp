/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:58:39 by thfirmin          #+#    #+#             */
/*   Updated: 2024/01/06 14:40:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>

// ATTRIBUTES |=================================================================
signed int	Rpn::_response = 0;
bool		Rpn::_isLoaded = false;
bool		Rpn::_isStarted = false;
std::stack<std::string>	Rpn::_stack;

// CONSTRUCTOR * DESTRUCTOR |===================================================
Rpn::Rpn(void) {}

Rpn::Rpn(const Rpn& src) {
	*this = src;
}

Rpn::~Rpn(void) {}

// OPERATOR |===================================================================
Rpn&	Rpn::operator=(const Rpn& src) {
	(void) src;
	return (*this);
}

// METHOD |=====================================================================
int	Rpn::_isOperator(char c) {
	const char ops[] = "+-*/";
	int			enumIdx = -1;

	while (ops[++enumIdx])
		if (c == ops[enumIdx])
			return (enumIdx + 1);
	return (OP_NULL);
}

void	Rpn::load(const std::string& expr) {
	std::string::const_iterator it = expr.begin();
	int							nbrStack = 0;

	for (std::string::const_iterator end = expr.end(); it != end; it++) {
		if (*it == ' ')
			continue ;

		if (isdigit(*it)) {
			nbrStack ++;
		}
		else if (_isOperator(*it)) {
			if (nbrStack >= 2)
				nbrStack --;
			else
				throw std::logic_error("Invalid Expression");
		}
		else {
			throw std::logic_error("Invalid character");
		}

		_stack.push(std::string(1, *it)); 
	}

	if (nbrStack != 1)
		throw std::logic_error("Invalid Expression");

	_isLoaded = true;
}

// 1 2 + 3 4 + -
// 1 2 + 3 -
// 1 2 3 + -

void	Rpn::start(void) {
	static int stackFunction;
	int op = OP_NULL,
		nbr1 = 0,
		nbr2 = 0;
	char res[12] = {0};

	stackFunction ++;
	(void) op;
	(void) nbr1;
	(void) nbr2;

	if (_isOperator(_stack.top().at(0)) && (_stack.size() != 1)) {
		op = _isOperator(_stack.top().at(0));
		_stack.pop();
		start();
		nbr1 = atoi(_stack.top().c_str());
		_stack.pop();
		start();
		nbr2 = atoi(_stack.top().c_str());
		_stack.pop();
		switch (op) {
			case(OP_SUM):
				sprintf(res, "%d", (nbr2 + nbr1));
				//res = itoa((nbr2 + nbr1), 12, 10);
				break ;
			case (OP_SUB):
				sprintf(res, "%d", (nbr2 - nbr1));
				//res = itoa((nbr2 - nbr1), 12, 10);
				break ;
			case (OP_MULT):
				sprintf(res, "%d", (nbr2 * nbr1));
				//res = itoa((nbr2 * nbr1), 12, 10);
				break ;
			case (OP_DIV):
				sprintf(res, "%d", (nbr2 / nbr1));
				//res = itoa((nbr2 / nbr1), 12, 10);
				break ;
			default:
				throw std::logic_error("An unexpected error occurred");
				break ;
		}
		_stack.push(std::string(res));
	}

	if (stackFunction == 1) {
		_response = atoi(_stack.top().c_str());
		_stack.pop();
		_isStarted = true;
	}

	stackFunction --;
}

// GETTER * SETTER |============================================================
int	Rpn::getResponse(void) {
	if (!Rpn::_isLoaded)
		throw std::logic_error("Expression need to be loaded before");
	if (!Rpn::_isStarted)
		throw std::logic_error("Expression need to be started before");

	return (Rpn::_response);
}

bool	Rpn::isLoaded(void) {
	return (Rpn::_isLoaded);
}

bool	Rpn::isStarted(void) {
	return (Rpn::_isStarted);
}
