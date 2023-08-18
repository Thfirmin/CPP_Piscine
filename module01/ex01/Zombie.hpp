/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:01:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/17 23:37:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class	Zombie {
	private:
		std::string name;

	public:
		Zombie( void );
		Zombie( std::string _name );
		~Zombie( void );

		void	setName( const std::string& name );
		void	announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif
