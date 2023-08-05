/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:44:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/04 23:09:32 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

struct	CtList;

class	ClapTrap {
	public:
		// Constructor * Destructor
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const& src );
		~ClapTrap( void );

		// Methods
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
		
		// Operator
		ClapTrap&	operator=( ClapTrap const& sign );

		// Getter * Setter
		std::string		getName( void ) const;
		void			setName( std::string name );
		int				getHitPoints( void ) const;
		void			setHitPoints( int hitPoints );
		int				getEnergyPoints( void ) const;
		void			setEnergyPoints( int energyPoints );
		int				getAttackDamage( void ) const;
		void			setAttackDamage( int attackDamage );
		static CtList*	getCtList( void );

	private:
		// Variables
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
		static CtList*	_instList;

		// Static
		static std::string	_authName( std::string const& name );
		static void			_ctAddBack( ClapTrap* clapTrap );
		static void			_ctDeleteOne( ClapTrap* clapTrap );
		
		// Getter * Setter
		static ClapTrap*	_getClapTrap( std::string const& name );
};

// Structs
struct	CtList {
	CtList( ClapTrap* clapTrap );
	~CtList( void );

	ClapTrap*		clapTrap;
	struct CtList*	next;
};

// Debuggers
std::ostream&	operator<<( std::ostream& out, ClapTrap const& ct );

std::ostream&	operator<<( std::ostream& out, CtList* ctList );

#endif
