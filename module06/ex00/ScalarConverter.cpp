/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"

// ATTRIBUTE |=================================================================
enum e_type		ScalarConverter::_type = SCLR_NULL;
union u_data	ScalarConverter::_data = { .dbl = 0.0 };

// CONSTRUCTOR * DESTRUCTOR |===================================================
ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

// METHOD |=====================================================================
void	ScalarConverter::convert(std::string literal) {
	_initData();
	_setScalarData(literal);
	std::cout << "ScalarConverter [\e[33m" << literal << "\e[0m] {" << std::endl;
	std::cout << "\tchar: \e[32m" << putChar(literal) << "\e[0m" << std::endl;
	std::cout << "\tint: \e[32m" << putInt(literal) << "\e[0m" << std::endl;
	std::cout << "\tfloat: \e[32m" << putFloat(literal) << "\e[0m" << std::endl;
	std::cout << "\tdouble: \e[32m" << putDouble(literal) << "\e[0m" << std::endl;
	std::cout << "}" << std::endl;
	return ;
}

void	ScalarConverter::_setScalarData(const std::string& str) {
	if (literalIsChar(str)) {
		_data.chr = str.at(0);
		_type = SCLR_CHAR;
	}
	else if (literalIsInt(str)) {
		_data.nbr = atoi(str.c_str());
		_type = SCLR_INT;
	}
	else if (literalIsFloat(str)) {
		_data.flt = strtof(str.c_str(), NULL);
		_type = SCLR_FLOAT;
	}
	else if (literalIsDouble(str)) {
		_data.dbl = strtod(str.c_str(), NULL);
		_type = SCLR_DOUBLE;
	}
	else
		_type = SCLR_NULL;
	return ;
}

void	ScalarConverter::_initData(void) {
	_type = SCLR_NULL;
	memset(&_data, 0, sizeof(_data));
	return ;
}

bool	ScalarConverter::literalIsChar(const std::string& str) {
	char	chr;

	if (str.empty() || (str.size() > 1)) {
		return (false);
	}
	chr = str.at(0);
	if (isdigit(chr)) {
		return (false);
	}
	return (true);
}

bool	ScalarConverter::literalIsInt(const std::string& str) {
	std::string::const_iterator	it = str.begin();

	if ((*it == '-') || (*it == '+')) {
		++ it;
	}
	while (it != str.end()) {
		if (!isdigit(*it)) {
			return (false);
		}
		++ it;
	}
	return (true);
}

bool	ScalarConverter::literalIsFloat(const std::string& str) {
	std::string::const_iterator	it = str.begin();
	bool					sign = false;

	if ((*it == '-') || (*it == '+')) {
		++ it;
	}
	while (it != str.end()) {
		if ((it + 1) == str.end()) {
			break ;
		}
		else if (*it == '.') {
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
	if (*it == 'f')
		return (true);
	return (false);
}

bool	ScalarConverter::literalIsDouble(const std::string& str) {
	std::string::const_iterator	it = str.begin();
	bool					sign = false;

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

std::string	ScalarConverter::putChar(const std::string& str) {
	std::string	msg;
	char		chr;

	(void) str;
	try {
		switch (_type) {
			case (SCLR_CHAR):
				chr = _data.chr;
				break ;
			case (SCLR_INT):
				chr = char(_data.nbr);
				break ;
			case (SCLR_FLOAT):
				chr = char(_data.flt);
				break ;
			case (SCLR_DOUBLE):
				chr = char(_data.dbl);
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

std::string	ScalarConverter::putInt(const std::string& str) {
	std::stringstream	msg;
	int					nbr;

	(void) str;
	try {
		switch (_type) {
			case (SCLR_CHAR):
				nbr = int(_data.chr);
				break ;
			case (SCLR_INT):
				nbr = _data.nbr;
				break ;
			case (SCLR_FLOAT):
				nbr = int(_data.flt);
				break ;
			case (SCLR_DOUBLE):
				nbr = int(_data.dbl);
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

std::string	ScalarConverter::putFloat(const std::string& str) {
	std::stringstream	msg;
	float				flt;

	(void) str;
	try {
		switch (_type) {
			case (SCLR_CHAR):
				flt = float(_data.chr);
				break ;
			case (SCLR_INT):
				flt = float(_data.nbr);
				break ;
			case (SCLR_FLOAT):
				flt = _data.flt;
				break ;
			case (SCLR_DOUBLE):
				flt = float(_data.dbl);
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

std::string	ScalarConverter::putDouble(const std::string& str) {
	std::stringstream	msg;
	double				dbl;

	(void) str;
	try {
		switch (_type) {
			case (SCLR_CHAR):
				dbl = double(_data.chr);
				break ;
			case (SCLR_INT):
				dbl = double(_data.nbr);
				break ;
			case (SCLR_FLOAT):
				dbl = double(_data.flt);
				break ;
			case (SCLR_DOUBLE):
				dbl = _data.dbl;
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

// OPERATOR |===================================================================
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src) {
	(void) src;
	return (*this);
}

// GETTER * SETTER |============================================================
