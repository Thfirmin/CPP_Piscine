/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:16 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 02:02:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Harl {
	private:
		// Variable
		static int	nbTypes;

		// Functions
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		// Constructors * Destructors
		Harl( void );
		~Harl( void );

		// Functions
		void	complain( std::string level );
};

#endif
