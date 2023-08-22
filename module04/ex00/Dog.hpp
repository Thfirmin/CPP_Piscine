/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:20:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/21 22:02:36 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);

		void	makeSound(void) const;

		Dog&	operator=(const Dog& sign);

	protected:
	private:
};

#endif
