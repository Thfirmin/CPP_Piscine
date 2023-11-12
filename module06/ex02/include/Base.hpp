/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:40:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/12 00:45:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <exception>
# include <time.h>
# include <stdlib.h>

class	Base {
	public:
		virtual ~Base(void);
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
