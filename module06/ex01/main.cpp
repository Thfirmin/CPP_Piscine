/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:20:50 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/08 21:38:49 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data		thino(true, 42, "Thinotsu");
	uintptr_t	raw;
	Data		*ptr;

	raw = Serializer::serialize(&thino);
	ptr = Serializer::deserialize(raw);
	std::cout << thino;
	std::cout << "raw: " << raw << std::endl;
	std::cout << *ptr;
	return (0);
}
