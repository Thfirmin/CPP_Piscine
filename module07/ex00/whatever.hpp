/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:12:05 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 19:44:48 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename Any>

void	swap(Any& elem1, Any& elem2)
{
	Any	aux;

	aux = elem1;
	elem1 = elem2;
	elem2 = aux;
	return ;
}

template <typename Any>

Any	min(const Any& elem1, const Any& elem2)
{
	return (elem1 < elem2 ? elem1 : elem2);
}

template <typename Any>

Any	max(const Any& elem1, const Any& elem2)
{
	return (elem1 > elem2 ? elem1 : elem2);
}

#endif
