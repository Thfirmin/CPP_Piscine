/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:44:00 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/05 00:29:17 by thfirmin         ###   ########.fr       */
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
		

		// Getter * Setter
		std::string		getName( void ) const;
		int				getHitPoints( void ) const;
		int				getEnergyPoints( void ) const;
		int				getAttackDamage( void ) const;
		static CtList*	getCtList( void );

		// Operator
		ClapTrap&	operator=( ClapTrap const& sign );

	protected:
		void			setName( std::string name );
		void			setHitPoints( int hitPoints );
		void			setEnergyPoints( int energyPoints );
		void			setAttackDamage( int attackDamage );

		static std::string	_authName( std::string const& name );

	private:
		// Variables
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;

		static CtList*	_instList;

		// Static
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
