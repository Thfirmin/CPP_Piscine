/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:31:57 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/27 22:05:35 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define FRM_MIN_GRADE 150
# define FRM_MAX_GRADE 1

#include <iostream>
#include <string>
#include <exception>

typedef unsigned short grade_t;

class	Bureaucrat;

class	Form {
	public:
		Form(void);
		Form(const Form& src);
		Form(const std::string& name, const grade_t gradeToSign, const grade_t gradeToExec, const bool sign );
		~Form(void);

		void	beSigned(Bureaucrat& assignment);

		Form&	operator=(const Form& src);
		
		const std::string	getName(void) const;
		grade_t		getGradeToSign() const;
		grade_t		getGradeToExec() const;
		bool			getSign(void) const;

		void				setSign(bool sign);

		class	GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(void) throw();
				GradeTooHighException(const std::string& context) throw();
				~GradeTooHighException(void) throw();

				const char*	what(void) const throw();

			private:
				std::string	_context;
		};

		class	GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(void) throw();
				GradeTooLowException(const std::string& context) throw();
				~GradeTooLowException(void) throw();

				const char*	what(void) const throw();

			private:
				std::string	_context;
		};

	private:
		const std::string	_name;
		const grade_t		_gradeToSign;
		const grade_t		_gradeToExec;
		bool				_sign;

		static void	validateGrade(const grade_t grade);
};

std::ostream&	operator<<(std::ostream& out, const Form& src);

#endif
