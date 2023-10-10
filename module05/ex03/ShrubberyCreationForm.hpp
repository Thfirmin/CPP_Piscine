/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 05:28:23 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);

		void	execute(const Bureaucrat& bureaucrat) const;

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);

	private:
		static const std::string	_type;
		static const grade_t		_stdGradeToSign;
		static const grade_t		_stdGradeToExec;
};

#endif
