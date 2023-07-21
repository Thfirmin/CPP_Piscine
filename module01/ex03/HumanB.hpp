/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:05:11 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/21 01:38:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class	HumanB {
	private:
		std::string	name;
		Weapon*		weapon;

	public:
		HumanB(std::string _name);
		HumanB(std::string _name, Weapon& _weapon);
		~HumanB(void);

		void	setWeapon(Weapon& _weapon);
		void	setWeapon(Weapon* _weapon);
		void	attack(void);
};

#endif
