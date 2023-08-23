/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:27:52 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/21 22:02:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat(void);
		Cat(const Cat& src);
		~Cat(void);

		void	makeSound(void) const;

		Cat&	operator=(const Cat& sign);

	protected:
	private:
};

#endif
