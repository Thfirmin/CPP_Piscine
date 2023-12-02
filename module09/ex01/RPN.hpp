/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:57:38 by thfirmin          #+#    #+#             */
/*   Updated: 2023/12/02 18:01:45 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

class	RPN {
	public:
		RPN(void);
		RPN(const RPN& src);
		~RPN(void);

		RPN&	operator=(const RPN& src);
};

#endif
