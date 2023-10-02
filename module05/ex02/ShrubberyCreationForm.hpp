/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:23:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 20:50:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);

		void	execute(const Bureaucrat& executor) const;

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);

	private:
		ShrubberyCreationForm(void);
};

#endif
