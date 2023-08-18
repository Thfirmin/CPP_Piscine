/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 00:59:16 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/18 00:12:07 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# include <cctype>

class	Harl {
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string level );

	private:
		static const int			_nbLevels;
		static const std::string	_levelTypes[];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif
