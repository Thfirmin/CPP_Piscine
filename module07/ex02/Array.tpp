/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:27:31 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/14 17:16:31 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

// CONSTRUCTOR * DESTRUCTOR |===================================================
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	return ;
}

template <typename T>
Array<T>::Array(const Array<T>& src) : _array(NULL), _size(src.size()) {
	*this = src;
	return ;
}

template <typename T>
Array<T>::Array(uint n) : _array(NULL), _size(n) {
	this->_array = new T[n];
	memset(this->_array, 0, (n * sizeof(T)));
	return ;
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->_array;
	return ;
}

// OPERATOR |===================================================================
template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& src) {
	uint	size = src.size();

	delete [] this->_array;

	this->_array = NULL;
	if (size) {
		this->_array = new T[size];
		memset(this->_array, 0, (size * sizeof(T)));
	}

	for (uint i = 0; i < size; i ++) {
		*(this->_array + i) = *(src.ptr() + i);
	};

	return (*this);
}

template <typename T>
T&	Array<T>::operator[](const int idx) {
	if ((idx < 0) || (static_cast<uint>(idx) >= this->_size)) {
		throw std::logic_error("Index is out of bounds");
	}
	return (*(this->_array + idx));
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& log) {
	uint	size = log.size();
	T*		ptr = log.ptr();

	out << "[";
	if (ptr) {
		for (uint i = 0; i < size; i ++) {
			out << *(ptr + i) << (i != (size - 1) ? ", " : "");
		}
	}
	out << "]" << std::endl;
	return (out);
}

// METHOD |=====================================================================
template <typename T>
uint	Array<T>::size(void) const {
	return (this->_size);
}

template <typename T>
T*	Array<T>::ptr(void) const {
	return (this->_array);
}
