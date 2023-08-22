/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfirmin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 23:51:45 by thfirmin          #+#    #+#             */
/*   Updated: 2023/08/22 10:57:33 by thfirmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void	testingWrongAnimal(const WrongAnimal wAnimal, const WrongAnimal& wAnimalRef, const WrongAnimal* wAnimalPtr);

static void	testingAnimal(const Animal *animalPtr, const Animal& animalRef);

int	main(void)
{
	std::cout << "--------------------|   Heap's Object Tests   |--------------------" << std::endl;
	Dog*	dogPtr = new Dog();
	Cat*	catPtr = new Cat();
	testingAnimal(dogPtr, *catPtr);

	delete dogPtr;
	delete catPtr;
	std::cout << "___________________________________________________________________" << std::endl;

	std::cout << "--------------------|  Stack's Object Tests   |--------------------" << std::endl;
	Dog	dogRef;
	Cat	catRef;
	testingAnimal(&dogRef, catRef);
	std::cout << "___________________________________________________________________" << std::endl;

	std::cout << "--------------------| Virtual Inherance Tests |--------------------" << std::endl;
	const	Animal*	animalPtr = new Dog();
	const	Animal	animalRef = Cat();

	testingAnimal(animalPtr, animalRef);
	testingAnimal(&animalRef, *animalPtr);

	delete animalPtr;
	std::cout << "___________________________________________________________________" << std::endl;
	
	std::cout << "--------------------|    WrongAnimal Tests    |--------------------" << std::endl;
	const WrongAnimal*	wCatPtr = new WrongCat();

	testingWrongAnimal(*wCatPtr, *wCatPtr, wCatPtr);

	delete wCatPtr;
	std::cout << "___________________________________________________________________" << std::endl;

	return 0;
}

static void	testingAnimal(const Animal* animalPtr, const Animal& animalRef)
{
	std::cout << "\e[1;2;3;4;7;35mTesting Animal in pointer and Reference\e[0m" << std::endl;
	std::cout << "|   Pointer* (" << animalPtr << ")=> \e[34m" << animalPtr->getType() << "\e[0m does ";
	animalPtr->makeSound();

	std::cout << "|   Reference& (" << &animalRef << ")=> \e[34m" << animalRef.getType() << "\e[0m does ";
	animalRef.makeSound();

	std::cout << std::endl;
}

static void	testingWrongAnimal(const WrongAnimal wAnimal, const WrongAnimal& wAnimalRef, const WrongAnimal* wAnimalPtr)
{
	std::cout << "\e[1;2;3;4;7;35mTesting Wrong Animal in pointer and Reference\e[0m" << std::endl;
	std::cout << "|   Stack (" << &wAnimal << ")=> \e[34m" << wAnimal.getType() << "\e[0m does ";
	wAnimal.makeSound();

	std::cout << "|   Reference& (" << &wAnimalRef << ")=> \e[34m" << wAnimalRef.getType() << "\e[0m does ";
	wAnimalRef.makeSound();

	std::cout << "|   Pointer* (" << wAnimalPtr << ")=> \e[34m" << wAnimalPtr->getType() << "\e[0m does ";
	wAnimalPtr->makeSound();

	std::cout << std::endl;
}
