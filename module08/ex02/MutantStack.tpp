/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:18:09 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 23:16:10 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <cstring>

// CONSTRUCTOR * DESTRUCTOR |===================================================

// MutantStack
template <class T>
MutantStack<T>::MutantStack(void) : _container(NULL), _empty(true) {}

template <class T>
MutantStack<T>::~MutantStack(void) {
	if (!this->_empty) {
		MContainer<T>*	node;
		while (this->_container) {
			node = this->_container->getNext();
			delete this->_container;
			this->_container = node;
		}
	}
}

// MContainer
template <class T>
MContainer<T>::MContainer(const T& content) : _content(content), _next(NULL) {}

template <class T>
MContainer<T>::MContainer(const T& content, MContainer<T>* next) : _content(content), _next(next) {}

template <class T>
MContainer<T>::~MContainer(void) {}

// METHOD |=====================================================================

// MutantStack

template <class T>
bool	MutantStack<T>::empty(void) const {
	return (this->_empty);
}

template <class T>
size_t	MutantStack<T>::size(void) const {
	MContainer<T>*	list = this->_container;
	size_t			size = 0;

	if (this->_empty)
		return (0);
	while (list) {
		size ++;
		list = list->getNext();
	}
	return (size);
}

template <class T>
T&	MutantStack<T>::top(void) {
	if (this->_empty) {
		throw std::logic_error("top can't be executed: MutantStack is empty");
	}
	return (this->_container->getContent());
}

template <class T>
const T&	MutantStack<T>::top(void) const {
	if (this->_empty) {
		throw std::logic_error("top can't be executed: MutantStack is empty");
	}
	return (this->_container->getContent());
}


template <class T>
void	MutantStack<T>::push(const T& elem) {
	if (this->_empty) {
		this->_container = new MContainer<T>(elem);
		this->_empty = false;
	}
	else {
		MContainer<T>*	node = new MContainer<T>(elem, this->_container);
		this->_container = node;
	}
}

template <class T>
void	MutantStack<T>::pop(void) {
	MContainer<T>*	node = NULL;

	if (this->_empty)
		return ;
	node = this->_container->getNext();
	delete this->_container;
	this->_container = node;
	if (!this->_container)
		this->_empty = true;
}

// MContainer
template <class T>
const T&	MContainer<T>::getContent(void) const {
	return (this->_content);
}

template <class T>
T&	MContainer<T>::getContent(void) {
	return (this->_content);
}

template <class T>
MContainer<T>*	MContainer<T>::getNext(void) const {
	return (this->_next);
}
