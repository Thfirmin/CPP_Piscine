/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:02:55 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 01:32:26 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap( void );
		DiamondTrap( DiamondTrap const& src );
		DiamondTrap( std::string name );
		~DiamondTrap( void );

		DiamondTrap& operator=( DiamondTrap const& sign );

	protected:
		static const std::string	_stdName;
		static const int			_stdHitPoints;
		static const int			_stdEnergyPoints;
		static const int			_stdAttackDamage;

	private:
		std::string	name;
};

#endif
