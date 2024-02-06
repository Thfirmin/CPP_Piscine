/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:39 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/06 16:44:38 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTERUTILS_HPP
# define SCALARCONVERTERUTILS_HPP

# include <string>
# include <cctype>
# include <cstdlib>
# include <sstream>
# include <exception>
# include <stdexcept>

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

typedef struct	s_dataType {
	enum e_type		type;
	union u_data	data;
}					t_dataType;

t_dataType	newDataType(e_type type = SCLR_NULL, u_data data = (u_data){.nbr = 0});

void	setScalarDataType(t_dataType& dataType, const std::string& str);

bool	isChar(const std::string& str);
bool	isInt(const std::string& str);
bool	isFloat(const std::string& str);
bool	isDouble(const std::string& str);

std::string	putChar(const t_dataType& dataType);
std::string	putInt(const t_dataType& dataType);
std::string	putFloat(const t_dataType& dataType, const std::string& str);
std::string	putDouble(const t_dataType& dataType, const std::string& str);

#endif
