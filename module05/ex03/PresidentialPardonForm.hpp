/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 05:29:17 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm(void);

		void	execute(const Bureaucrat& bureaucrat) const;

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);

	private:
		static const std::string	_type;
		static const grade_t		_stdGradeToSign;
		static const grade_t		_stdGradeToExec;
};

#endif
