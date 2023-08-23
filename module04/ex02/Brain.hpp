/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:06:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 16:49:09 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# define BRAIN_MAX_IDEAS 100

# include <iostream>
# include <string>

class	Brain {
	public:
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);

		Brain&	operator=(const Brain& sign);

		const std::string&	getIdeas(int index) const;
		void	setIdeas(int index, const std::string& _idea);

	private:
		std::string	ideas[100];
};

std::ostream&	operator<<(std::ostream& out, const Brain& brain);

#endif
