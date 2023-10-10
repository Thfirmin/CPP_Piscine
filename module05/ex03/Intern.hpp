/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 06:29:06 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/10 07:45:29 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

typedef enum	e_form {
	shrubbery_creation = 0,
	robotomy_request = 1,
	presidential_pardon = 2,
	null_form = 3
}	t_form;

class	AForm;

class	Intern {
	public:
		Intern(void);
		Intern(const Intern& src);
		~Intern(void);

		AForm*			makeForm(const std::string& formName, const std::string& target);

		Intern&	operator=(const Intern& src);

	private:
		static t_form	hashForm(const std::string& form);
};

std::ostream&	operator<<(std::ostream& out, const Intern& log);

#endif
