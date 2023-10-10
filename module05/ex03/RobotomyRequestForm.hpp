/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/10/08 22:59:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);

	private:
		static const std::string	_type;
		static const grade_t		_stdGradeToSign;
		static const grade_t		_stdGradeToExec;
};

#endif
