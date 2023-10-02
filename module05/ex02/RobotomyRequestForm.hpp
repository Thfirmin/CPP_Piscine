/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:17:39 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/01 20:51:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm(void);

		void	execute(const Bureaucrat& executor) const;

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);

	private:
		RobotomyRequestForm(void);
};

#endif
