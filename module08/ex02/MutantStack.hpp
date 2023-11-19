/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/18 23:15:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <class T>
class	MContainer;

template <class T>
class	MutantStack {
	public:
		MutantStack<T>(void);
		~MutantStack<T>(void);

		bool	empty(void) const;
		size_t	size(void) const;
		T&			top(void);
		const T&	top(void) const;
		void		push(const T& elem);
		//void	emplace(void);
		void	pop(void);

	private:
		MContainer<T>*	_container;
		bool		_empty;
};


template <class T>
struct	MContainer {
	public:
		MContainer<T>(const T& content);
		MContainer<T>(const T& content, MContainer<T>* next);
		~MContainer<T>(void);

		const T&		getContent(void) const;
		T&				getContent(void);
		MContainer<T>*	getNext(void) const;


	private:
		T				_content;
		MContainer<T>*	_next;
};

# include "MutantStack.tpp"

#endif
