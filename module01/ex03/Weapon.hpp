/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:16:53 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 23:50:56 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon {
	private:
		std::string	type;

	public:
		Weapon(std::string _type);
		~Weapon(void);

		std::string	getType(void) const;
		void		setType(std::string _type);
};

#endif
