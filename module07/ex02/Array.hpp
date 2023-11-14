/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:21:54 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 22:44:11 by thfirmin         ###   ########.fr       */
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

		T&			operator[](int idx) const;
		Array<T>&	operator=(const Array<T>& src);

		T*		getArray(void) const;
		uint	size(void) const;

	private:
		T*		_array;
		uint	_size;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& arr);

# include "Array.tpp"

#endif
