/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:18:09 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/22 23:17:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <cstring>

// CONSTRUCTOR * DESTRUCTOR |===================================================
template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src) {}

template <class T>
MutantStack<T>::~MutantStack(void) {}

// OPERATOR |===================================================================
template <class T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& src) {
	if (this != &src) {
		std::stack<T>::operator=(src);
	}
	return (*this);
}

// METHOD |=====================================================================
template <class T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <class T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template <class T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cbegin(void) const {
	return (this->c.cbegin());
}

template <class T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::cend(void) const {
	return (this->c.cend());
}
