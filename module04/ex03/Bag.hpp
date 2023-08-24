/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bag.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 03:08:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 03:21:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BAG_HPP
# define BAG_HPP

class	AMateria;

struct	Bag {
	public:
		Bag(AMateria* m);
		~Bag(void);

	private:
		AMateria*	_content;
		Bag*		_next;
		static Bag*	_list;
};

#endif
