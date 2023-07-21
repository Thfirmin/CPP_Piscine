/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:02:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/21 01:30:11 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class	HumanA {
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA(std::string _name, Weapon& _weapon);
		~HumanA(void);

		void	setWeapon(std::string _type);
		void	attack(void);
};

#endif
