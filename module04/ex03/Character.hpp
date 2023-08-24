/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:59:42 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 03:25:46 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# define CHARACTER_MAX_INVENTORY 4

# include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character(void);
		Character(const Character& src);
		Character(const std::string& name);
		~Character(void);

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		Character&	operator=(const Character& sign);

		const std::string&	getName(void) const;
		const AMateria*		getMateria(int idx) const;

	private:
		std::string	_name;
		AMateria*	_inventory[CHARACTER_MAX_INVENTORY];
};

#endif
