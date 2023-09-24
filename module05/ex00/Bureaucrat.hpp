/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:59:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/09/24 01:56:03 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BUREAUCRAT_HIGHEST_GRADE 1
# define BUREAUCRAT_LOWEST_GRADE 150

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat(const unsigned int grade);
		Bureaucrat(const std::string& name, const unsigned int grade);
		~Bureaucrat(void);

		void	incrementGrade(void);
		void	decrementGrade(void);

		Bureaucrat&	operator=(const Bureaucrat& sign);

		const std::string&	getName(void) const;
		unsigned int	getGrade(void) const;

		class	GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(void) throw();

				const char*	what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(void) throw();

				const char*	what(void) const throw();
		};

	private:
		const std::string	_name;
		unsigned int		_grade;

		void	setGrade(unsigned int grade);
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
