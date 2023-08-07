/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:15:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/07 00:20:25 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

struct	ClapTrapList;

class	ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap( ClapTrap const& src );
		ClapTrap( std::string name );
		~ClapTrap( void );

		void	attack( std::string const& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		ClapTrap&	operator=( ClapTrap const& sign );

		std::string	getName( void ) const;
		void		setName( std::string name );
		int			getHitPoints( void ) const;
		void		setHitPoints( int hitPoints );
		int			getEnergyPoints( void ) const;
		void		setEnergyPoints( int energyPoints );
		int			getAttackDamage( void ) const;
		void		setAttackDamage( int attackDamage );

		static ClapTrapList*	getClapTrapList( void );

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
		static const std::string	_stdName;
		static const int			_stdHitPoints;
		static const int			_stdEnergyPoints;
		static const int			_stdAttackDamage;

		static ClapTrapList*		_clapTrapList;

		static void					_ctlPush( ClapTrap* inst );
		static void					_ctlDelete( ClapTrap* inst );
		static ClapTrap*			_ctlPull( std::string const& name );
		static std::string			_ctlAuthName( std::string const& name );

};

struct	ClapTrapList {
	ClapTrap*	inst;
	struct ClapTrapList*	next;
};

std::ostream&	operator<<( std::ostream& out, ClapTrap const& clap );
std::ostream&	operator<<( std::ostream& out, ClapTrapList const* list );

#endif
