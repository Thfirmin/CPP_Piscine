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
int	easyfind(T list, int find) {
	typename T::iterator	end = list.end();

	for (typename T::iterator it = list.begin(); it != end; ++ it) {
		if (*it == find) {
			std::cout << find << " founded in index: " << std::distance(list.begin(), it) << std::endl;
			return (std::distance(list.begin(), it));
		}
	}
	std::stringstream	stream;
	stream << find << " not founded";
	throw std::logic_error(stream.str());
	return (-1);
}
