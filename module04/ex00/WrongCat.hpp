/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:00:09 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/21 22:04:54 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& src);
		~WrongCat(void);

		void	makeSound(void) const;

		WrongCat&	operator=(const WrongCat& sign);
};

#endif
