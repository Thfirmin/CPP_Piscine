/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 23:51:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/23 17:03:52 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void		deleteFarm(Animal*** mem, int len);

Animal**	newFarm(int len);

void	printAnimalArray(Animal** farm, int arrLen);

int	main(void)
{
	int			arrLen = 10;
	int			half = arrLen * 0.5;
	Animal**	farm = newFarm(arrLen);

	farm[0]->getBrain().setIdeas(0, "Drink water");
	farm[0]->getBrain().setIdeas(1, "Bark");
	farm[0]->getBrain().setIdeas(2, "Growl");
	farm[0]->getBrain().setIdeas(3, "Wag your tail");
	farm[0]->getBrain().setIdeas(4, "Bite");

	farm[half]->getBrain().setIdeas(0, "Drink milk");
	farm[half]->getBrain().setIdeas(1, "Meow");
	farm[half]->getBrain().setIdeas(2, "Purr");
	farm[half]->getBrain().setIdeas(3, "Rub");
	farm[half]->getBrain().setIdeas(4, "Scratch");

	for (int i = 1; i < half; i ++)
		*farm[i] = *farm[0];
	for (int i = half + 1; i < arrLen; i ++)
		*farm[i] = *farm[half];

	printAnimalArray(farm, arrLen);

	deleteFarm(&farm, arrLen);
	return 0;
}

void	printAnimalArray(Animal** farm, int arrLen)
{
	for (int i = 0; i < arrLen; i ++)
	{
		std::cout << *farm[i];
		std::cout << "this Animal does say:" << std::flush;
		farm[i]->makeSound();
		std::cout << std::endl;
	}
	return ;
}

Animal**	newFarm(int len)
{
	Animal**	farm = new Animal*[len];
	int			i = 0;
	int			half = len * 0.5;

	while (i < half)
		farm[i++] = new Dog();
	while (i < len)
		farm[i++] = new Cat();
	return farm;
}

void	deleteFarm(Animal*** mem, int len)
{
	Animal**	aux = *mem;
	
	for (int i = 0; i < len; i ++)
		delete aux[i];
	delete [] aux;
	*mem = 0;
}
