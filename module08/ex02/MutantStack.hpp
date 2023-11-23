/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:16:34 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/22 23:16:22 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack(void);
		MutantStack(const MutantStack& src);
		~MutantStack(void);

		MutantStack<T>&	operator=(const MutantStack& src);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator	begin(void);
		iterator	end(void);
		const_iterator	cbegin(void) const;
		const_iterator	cend(void) const;

};

# include "MutantStack.tpp"

	#endif
