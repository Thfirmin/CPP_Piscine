/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:59:37 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/24 23:47:44 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define BUREAUCRAT_HIGHEST_GRADE 1
# define BUREAUCRAT_LOWEST_GRADE 150

# include <string>

class	Bureaucrat {
	public:
		Bureaucrat(const std::string& name, const unsigned int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat& sign);

		const std::string&	getName(void) const;
		unsigned int	getGrade(void) const;

	private:
		const std::string	_name;
		unsigned int		_grade;

		void	setGrade(unsigned int grade);
};

#endif
