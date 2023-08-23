/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:46:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 09:25:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal(void);

		virtual void	makeSound(void) const;

		virtual WrongAnimal&	operator=(const WrongAnimal& sign);

		const std::string&	getType(void) const;
		void	setType(const std::string& _type);

	protected:
		std::string	type;
};

#endif
