/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:57:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/12/02 18:27:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class	RPN {
	public:
		void start(std::string expr);

	private:
		RPN(void);
		RPN(const RPN& src);
		~RPN(void);

		std::stack<char>	_stack;

		RPN&	operator=(const RPN& src);

};

#endif
