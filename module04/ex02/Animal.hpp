/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:46:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/23 17:06:28 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class	Animal {
	public:
		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal(void);

		virtual void	makeSound(void) const = 0;

		Animal&	operator=(const Animal& sign);

		const std::string&	getType(void) const;
		void	setType(const std::string& _type);

		Brain&		getBrain(void) const;
		void	setBrain(Brain& _brain);

	protected:
		std::string	type;
		Brain*		brain;
};

std::ostream&	operator<<(std::ostream& out, const Animal& animal);

#endif
