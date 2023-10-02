/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:15:26 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 22:54:20 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BUREAUCRAT_MIN_GRADE (150)
# define BUREAUCRAT_MAX_GRADE (1)

# include <iostream>
# include <string>
# include <exception>

typedef	short unsigned int	grade_t;

class	AForm;

class	GradeException : public std::exception {
	public:
		GradeException(void) throw();
		GradeException(const std::string& context) throw();
		virtual ~GradeException(void) throw();

		const char*	what(void) const throw();

	protected:
		std::string	_context;
};

class	Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const std::string name, const grade_t grade);
		~Bureaucrat(void);

		static grade_t	authGrade(grade_t grade);
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(AForm& form);
		void			executeForm(const AForm& form);

		Bureaucrat&	operator=(const Bureaucrat& src);

		const std::string&	getName(void) const;
		grade_t				getGrade(void) const;

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

	private:
		const std::string	_name;
		grade_t				_grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src);

#endif
