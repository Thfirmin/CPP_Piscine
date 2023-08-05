/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:44:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 21:47:37 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

struct	CtList;

class	ClapTrap {
	public:
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const& src );
		~ClapTrap( void );

		void	attack( const std::string& target );
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

		static CtList*	getCtList( void );

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
		static CtList*	_instList;

		static void	_ctAddBack( ClapTrap* clapTrap );
		static void	_ctDeleteOne( ClapTrap* clapTrap );
		
		static ClapTrap*	_getClapTrap( std::string const& name );
};

struct	CtList {
	CtList( ClapTrap* clapTrap );
	~CtList( void );

	ClapTrap*		clapTrap;
	struct CtList*	next;
};

std::ostream&	operator<<( std::ostream& out, ClapTrap const& ct );

std::ostream&	operator<<( std::ostream& out, CtList* ctList );

#endif
