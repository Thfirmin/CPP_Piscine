/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/06 16:46:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "ScalarConverterUtils.hpp"
# include <iostream>
# include <cstring>
# include <cstdlib>

class	ScalarConverter {
	public:
		static void	convert(std::string literal);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);
		
		ScalarConverter&	operator=(const ScalarConverter& src);
};

#endif
