/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:47:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/20 19:48:34 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie( std::string _name );
		~Zombie( void );
		
		void	announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

#endif
