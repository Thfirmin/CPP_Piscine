/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:08:20 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 20:52:51 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm(void);

		void	execute(const Bureaucrat& executor) const;

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

	private:
		PresidentialPardonForm(void);
};

#endif
