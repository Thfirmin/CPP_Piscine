/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:08:02 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 23:08:18 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exception>

typedef unsigned int uint;

// CONSTRUCTOR * DESTRUCTOR |===================================================
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {
	return ;
}

template <typename T>
Array<T>::Array(const Array<T>& src) : _array(NULL), _size(src.size()) {
	*this = src;
	return ;
};

template <typename T>
Array<T>::Array(uint n) : _array(NULL), _size(n) {
	this->_array = new T[n];
	return ;
}

template <typename T>
Array<T>::~Array(void) {
	delete [] this->_array;
	return ;
}

// OPERATOR |===================================================================
template <typename T>
T&	Array<T>::operator[](int idx) const {
	if ((idx < 0) || (static_cast<uint>(idx) >= this->_size)) {
		throw std::logic_error("index is out of bounds");
	}
	return (*(this->_array + idx));
};

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& src) {
	delete [] this->_array;
	this->_array = NULL;
	if (src.size()) {
		this->_array = new T[src.size()];
		for (uint i = 0; i < src.size(); i ++) {
			*(this->_array + i) = src[i];
		};
	}
	return (*this);
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& log) {
	uint i = 0;

	out << "[";
	while (i < log.size()) {
		out << *(log.getArray() + i);
		i++;
		out << (i != log.size() ? ", " : "");
	}
	out << "]" << std::endl;
	return (out);
}

// GETTER * SETTER |============================================================
template <typename T>
T*	Array<T>::getArray(void) const {
	return (this->_array);
}

template <typename T>
uint	Array<T>::size(void) const {
	return (this->_size);
}
