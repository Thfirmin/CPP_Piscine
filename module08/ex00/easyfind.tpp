/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:43:46 by thfirmin          #+#    #+#             */
/*   Updated: 2023/11/15 21:39:05 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iterator>
# include <sstream>

template <class T>
int	easyfind(T list, int find)
{
	typename T::iterator	end = list.end();
	int						index;

	for (typename T::iterator it = list.begin(); it != end; ++ it)
	{
		if (*it == find)
		{
			index = std::distance(list.begin(), it);
			std::cout << find << " founded in index: " << index << std::endl;
			return (index);
		}
	}
	std::stringstream	stream;
	stream << find << " not founded";
	throw std::logic_error(stream.str());
}
