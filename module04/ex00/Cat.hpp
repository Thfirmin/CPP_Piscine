/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:27:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/20 11:28:50 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

class	Cat {
	public:
		Cat(void);
		Cat(const Cat& src);
		~Cat(void);

		Cat&	operator=(const Cat& sign);
};

#endif
