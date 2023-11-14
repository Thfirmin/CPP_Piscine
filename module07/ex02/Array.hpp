/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:24:32 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/14 17:14:15 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

typedef unsigned int uint;

template <typename T>
class	Array {
	public:
		Array<T>(void);
		Array<T>(const Array<T>& src);
		Array<T>(uint n);
		~Array<T>(void);

		Array<T>&	operator=(const Array<T>& src);
		T&			operator[](const int idx);

		uint	size(void) const;
		T*		ptr(void) const;

	private:
		T*		_array;
		uint	_size;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& log);

# include "Array.tpp"

#endif
