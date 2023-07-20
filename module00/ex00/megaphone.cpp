/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <thfirmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:32:43 by thfirmin          #+#    #+#             */
/*   Updated: 2023/07/16 20:22:06 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

char	*strToUpper(char *str) {
	char *aux = str;
	while (*aux) {
		*aux = toupper(*aux);
		aux ++;
	}
	return str;
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i ++) {
		std::cout << strToUpper(*(argv + i)) << (i != (argc - 1) ? " " : "");
	}
	std::cout << std::endl;
	return 0;
}
