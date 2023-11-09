/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 22:00:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include <iostream>
# include "Base.hpp"

class	C: public Base {
	public:
		C(void);
		C(const C& src);
		~C(void);

		C&	operator=(const C& src);
};

std::ostream&	operator<<(std::ostream& out, const C& log);

#endif
