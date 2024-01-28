/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:57:38 by thfirmin          #+#    #+#             */
/*   Updated: 2024/01/28 05:11:02 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Rpn_HPP
# define Rpn_HPP

# include <stack>
# include <string>

enum e_operations {
	OP_NULL,
	OP_SUM,
	OP_SUB,
	OP_MULT,
	OP_DIV
};

class	Rpn {
	public:
		static int calculate(const std::string& expr);
		static void load(const std::string& expr);
		static void	start(void);

		static int	getResponse(void);
		static bool	isLoaded(void);
		static bool	isStarted(void);

	private:
		Rpn(void);
		Rpn(const Rpn& copy);
		~Rpn(void);

		static std::stack<std::string>	_stack;
		static bool				_isLoaded;
		static bool				_isStarted;
		static signed int		_response;

		Rpn&	operator=(const Rpn& src);

		static int	_isOperator(char op);
};

#endif
