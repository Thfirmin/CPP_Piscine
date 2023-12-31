/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:46:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 09:27:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal {
	public:
		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;

		virtual Animal&	operator=(const Animal& sign);

		const std::string&	getType(void) const;
		void	setType(const std::string& _type);

	protected:
		std::string	type;
};

#endif
