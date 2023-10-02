/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:21:44 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:39:24 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# define AFORM_MIN_GRADE (150)
# define AFORM_MAX_GRADE (1)

# include <iostream>
# include <string>
# include <exception>
#include "Bureaucrat.hpp"

typedef	short unsigned int	grade_t;

class	Bureaucrat;

class	AForm {
	public:
		AForm(void);
		AForm(const AForm& src);
		AForm(const std::string target, const std::string& name, const grade_t gradeToSign, const grade_t gradeToExec);
		virtual ~AForm(void) = 0;

		static grade_t	authGrade(grade_t grade);
		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(const Bureaucrat& executor) const = 0;

		AForm&	operator=(const AForm& src);

		const std::string&	getTarget(void) const;
		const std::string&	getName(void) const;
		grade_t				getGradeToSign(void) const;
		grade_t				getGradeToExec(void) const;
		bool				getSign(void) const;

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
		const std::string	_target;

		static void	authExecutorRequirements(const Bureaucrat& executor, const AForm* form);

	private:
		const std::string	_name;
		grade_t		_gradeToSign;
		grade_t		_gradeToExec;
		bool			_sign;
};

std::ostream&	operator<<(std::ostream& out, const AForm* src);

#endif
