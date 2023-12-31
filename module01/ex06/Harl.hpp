/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:16 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/22 10:29:35 by thfirmin         ###   ########.fr       */
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
		static const int			_nbLevels;
		static const std::string	_levelTypes[];
		int							_levelFilter;

		// Functions
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		// Constructors * Destructors
		Harl( void );
		~Harl( void );

		// Getters * Setters
		int			levelFilter( void ) const;
		void		levelFilter( std::string level );

		// Functions
		void		complain( std::string level );
		static int	isLevel( std::string level );
};

#endif
