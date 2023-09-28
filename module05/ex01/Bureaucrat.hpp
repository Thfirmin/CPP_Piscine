/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:20:04 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/27 22:12:08 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BRCT_MAX_GRADE 1
# define BRCT_MIN_GRADE 150

#include <iostream>
#include <string>
#include <exception>

typedef	unsigned short grade_t;

class	Form;

class	Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const std::string& name, grade_t grade);
		~Bureaucrat(void);

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(Form& form);

		Bureaucrat&	operator=(const Bureaucrat& src);
		
		const std::string&	getName(void) const;
		grade_t				getGrade(void) const;

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
		grade_t				_grade;
		
		void	setGrade(grade_t grade);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src);

#endif
