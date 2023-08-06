/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 00:33:30 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:58:00 by thfirmin         ###   ########.fr       */
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

	private:
};

#endif
