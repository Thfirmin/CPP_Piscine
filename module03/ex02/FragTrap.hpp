/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:33:30 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 01:05:42 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap( FragTrap const& src );
		FragTrap( std::string name );
		~FragTrap( void );

		void	highFivesGuys( void );

		FragTrap&	operator=( FragTrap const& sign );

	protected:
		static const std::string	_stdName;
		static const int			_stdHitPoints;
		static const int			_stdEnergyPoints;
		static const int			_stdAttackDamage;
};

#endif
