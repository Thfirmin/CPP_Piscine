/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterUtils.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:40:01 by thfirmin          #+#    #+#             */
/*   Updated: 2024/02/06 16:43:58 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverterUtils.hpp"

t_dataType newDataType(e_type type, u_data data) {
	t_dataType	dataType = {type, data};

	return (dataType);
}

void	setScalarDataType(t_dataType& dataType, const std::string& str) {
	if (isChar(str)) {
		dataType.data.chr = str.at(0);
		dataType.type = SCLR_CHAR;
	}
	else if (isInt(str)) {
		dataType.data.nbr = atoi(str.c_str());
		dataType.type = SCLR_INT;
	}
	else if (isFloat(str)) {
		dataType.data.flt = strtof(str.c_str(), NULL);
		dataType.type = SCLR_FLOAT;
	}
	else if (isDouble(str)) {
		dataType.data.dbl = strtod(str.c_str(), NULL);
		dataType.type = SCLR_DOUBLE;
	}
	else
		dataType.type = SCLR_NULL;
	return ;
}

bool	isChar(const std::string& str) {
	if (str.empty() || (str.size() > 1))
		return (false);
	if (isdigit(str.at(0)))
		return (false);
	return (true);
}

bool	isInt(const std::string& str) {
	(void) str;
	std::string::const_iterator	it = str.begin();

	if ((*it == '-') || (*it == '+')) {
		++ it;
	}
	while (it != str.end()) {
		if (!isdigit(*it))
			return (false);
		++ it;
	}
	return (true);
}

bool	isFloat(const std::string& str) {
	std::string::const_iterator	it = str.begin();
	bool						sign = false;

	if ((*it == '-') || (*it == '+')) {
		++ it;
	}
	while (it != str.end()) {
		if ((it + 1) == str.end()) {
			break ;
		}
		else if (*it == '.') {
			if (sign)
				return (false);
			sign = true;
		}
		else if (!isdigit(*it)) {
			return (false);
		}
		++ it;
	}
	if (*it == 'f')
		return (true);
	return (false);
}

bool	isDouble(const std::string& str) {
	std::string::const_iterator	it = str.begin();
	bool						sign = false;

	if ((*it == '-') || (*it == '+')) {
		++ it;
	}
	while (it != str.end()) {
		if (*it == '.') {
			if (sign) {
				return (false);
			}
			sign = true;
		}
		else if (!isdigit(*it)) {
			return (false);
		}
		++ it;
	}
	return (true);
}

std::string	putChar(const t_dataType& dataType) {
	std::string	msg;
	char		chr;

	try {
		switch (dataType.type) {
			case (SCLR_CHAR):
				chr = dataType.data.chr;
				break ;
			case (SCLR_INT):
				chr = char(dataType.data.nbr);
				break ;
			case (SCLR_FLOAT):
				chr = char(dataType.data.flt);
				break ;
			case (SCLR_DOUBLE):
				chr = char(dataType.data.dbl);
				break ;
			default:
				throw std::logic_error("Impossible");
		};
		if (!isprint(chr)) {
			throw std::logic_error("Non Displayable");
		}
		msg = chr;
	}
	catch (std::exception& e) {
		msg = e.what();
	};

	return (msg);
}

std::string	putInt(const t_dataType& dataType) {
	std::stringstream	msg;
	int					nbr;

	try {
		switch (dataType.type) {
			case (SCLR_CHAR):
				nbr = int(dataType.data.chr);
				break ;
			case (SCLR_INT):
				nbr = dataType.data.nbr;
				break ;
			case (SCLR_FLOAT):
				nbr = int(dataType.data.flt);
				break ;
			case (SCLR_DOUBLE):
				nbr = int(dataType.data.dbl);
				break ;
			default:
				throw std::logic_error("Impossible");
				break ;
		};
		msg << nbr;
	}
	catch (std::exception& e) {
		msg << e.what();
	};

	return (msg.str());
}

std::string	putFloat(const t_dataType& dataType, const std::string& str) {
	std::stringstream	msg;
	float				flt;

	try {
		switch (dataType.type) {
			case (SCLR_CHAR):
				flt = float(dataType.data.chr);
				break ;
			case (SCLR_INT):
				flt = float(dataType.data.nbr);
				break ;
			case (SCLR_FLOAT):
				flt = dataType.data.flt;
				break ;
			case (SCLR_DOUBLE):
				flt = float(dataType.data.dbl);
				break ;
			default:
				if ((str == "nan") || (str == "nanf"))
					throw std::logic_error("nanf");
				else if ((str == "+inf") | (str == "+inff"))
					throw std::logic_error("+inff");
				else if ((str == "-inf") || (str == "-inff"))
					throw std::logic_error("-inff");
				else
					throw std::logic_error("Impossible");
				break ;
		};
		msg << flt;
	}
	catch (std::exception& e) {
		msg << e.what();
	};

	return (msg.str());
}

std::string	putDouble(const t_dataType& dataType, const std::string& str) {
	std::stringstream	msg;
	double				dbl;

	try {
		switch (dataType.type) {
			case (SCLR_CHAR):
				dbl = double(dataType.data.chr);
				break ;
			case (SCLR_INT):
				dbl = double(dataType.data.nbr);
				break ;
			case (SCLR_FLOAT):
				dbl = double(dataType.data.flt);
				break ;
			case (SCLR_DOUBLE):
				dbl = dataType.data.dbl;
				break ;
			default:
				if ((str == "nan") || (str == "nanf"))
					throw std::logic_error("nan");
				else if ((str == "+inf") || (str == "+inff"))
					throw std::logic_error("+inf");
				else if ((str == "-inf") || (str == "-inff"))
					throw std::logic_error("-inf");
				else
					throw std::logic_error("Impossible");
				break ;
		};
		msg << dbl;
	}
	catch (std::exception& e) {
		msg << e.what();
	};

	return (msg.str());
}
