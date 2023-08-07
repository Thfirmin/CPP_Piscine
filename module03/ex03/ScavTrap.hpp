/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:41:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 01:13:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( ScavTrap const& src );
		ScavTrap( std::string name );
		~ScavTrap( void );

		void	guardGate( void );

		ScavTrap&	operator=( ScavTrap const& sign );

	protected:
		static const std::string	_stdName;
		static const int			_stdHitPoints;
		static const int			_stdEnergyPoints;
		static const int			_stdAttackDamage;
};

#endif
