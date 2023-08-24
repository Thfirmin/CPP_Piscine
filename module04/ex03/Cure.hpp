/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:53:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 02:51:00 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {
	public:
		Cure(void);
		Cure(const Cure& src);
		~Cure(void);

		Cure*	clone() const;
		void	use(ICharacter& target);

		Cure&	operator=(const Cure& sign);
};

#endif
