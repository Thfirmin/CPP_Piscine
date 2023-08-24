/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:14:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 02:54:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class	ICharacter;

class	AMateria {
	public:
		AMateria(void);
		AMateria(const AMateria& src);
		AMateria(const std::string& type);
		virtual ~AMateria(void);

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

		virtual AMateria&	operator=(const AMateria& sign);

		const std::string&	getType(void) const;

	protected:
		std::string	_type;
};

#endif
