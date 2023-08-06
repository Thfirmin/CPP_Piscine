/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:41:58 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:23:21 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		// Constructor * Destructor
		ScavTrap( void );
		ScavTrap( ScavTrap const& src );
		ScavTrap( std::string name );
		~ScavTrap( void );

		void	guardGate( void );

		ScavTrap&	operator=( ScavTrap const& sign );

	private:
};

#endif
