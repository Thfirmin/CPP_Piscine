/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:12:22 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 19:45:04 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <sstream>
# include <cctype>
# include <cstring>
# include <cstdlib>

enum	e_type {
	SCLR_NULL,
	SCLR_CHAR,
	SCLR_INT,
	SCLR_FLOAT,
	SCLR_DOUBLE
};

union	u_data {
	char	chr;
	int		nbr;
	float	flt;
	double	dbl;
};

class	ScalarConverter {
	public:
		static void	convert(std::string literal);

		static bool	literalIsChar(const std::string& str);
		static bool	literalIsInt(const std::string& str);
		static bool	literalIsFloat(const std::string& str);
		static bool	literalIsDouble(const std::string& str);

		static std::string	putChar(const std::string& str);
		static std::string	putInt(const std::string& str);
		static std::string	putFloat(const std::string& str);
		static std::string	putDouble(const std::string& str);

	private:
		static enum e_type	_type;
		static union u_data	_data;

		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter(void);
		
		static void	_initData(void);
		static void	_setScalarData(const std::string& str);

		ScalarConverter&	operator=(const ScalarConverter& src);
};

#endif
