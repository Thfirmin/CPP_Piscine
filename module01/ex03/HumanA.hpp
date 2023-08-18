/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:02:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 23:55:02 by thfirmin         ###   ########.fr       */
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

		void	setWeapon(const std::string& _type);
		void	attack(void);
};

#endif
