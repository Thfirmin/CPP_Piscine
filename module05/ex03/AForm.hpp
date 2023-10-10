/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/08 23:08:32 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define AFORM_MIN_GRADE (150)
# define AFORM_MAX_GRADE (1)

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

typedef short unsigned int	grade_t;

class AForm {
	public:
		AForm(void);
		AForm(const AForm& src);
		AForm(const std::string& name, const grade_t requireGradeToSign, const grade_t requiredGradeToExec);
		virtual ~AForm(void) = 0;

		static grade_t	authGrade(const grade_t grade);
		void			beSigned(const Bureaucrat& bureaucrat);
		
		AForm&	operator=(const AForm& src);

		const std::string&	getName(void) const;
		const std::string&	getTarget(void) const;
		grade_t				getRequiredGradeToSign(void) const;
		grade_t				getRequiredGradeToExec(void) const;
		bool				getSign(void) const;

		void				setTarget(const std::string& target);

		class	GradeTooHighException : public GradeException {
			public:
				GradeTooHighException(void) throw();
				GradeTooHighException(const std::string& context) throw();
		};

		class	GradeTooLowException : public GradeException {
			public:
				GradeTooLowException(void) throw();
				GradeTooLowException(const std::string& context) throw();
		};

	protected:
		std::string			_target;

		void	setSign(const bool sign);

	private:
		const std::string	_name;
		grade_t				_requiredGradeToSign;
		grade_t				_requiredGradeToExec;
		bool				_sign;
};

std::ostream&	operator<<(std::ostream& out, const AForm* log);

#endif
