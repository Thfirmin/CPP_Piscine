/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:00:35 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/13 20:56:16 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>

void	iter(T* address, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i ++)
	{
		f(*(address + i));
	}
	return ;
}

#endif
