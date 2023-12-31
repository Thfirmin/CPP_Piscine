#include <iostream>
#include <Array.hpp>
#include <stdlib.h>

#define MAX_VAL 750


int	main(void)
{
	Array<int>	arr(5);
	std::cout << "arr(5): " << arr;
	
	Array<int>	arr2(arr);
	std::cout << "arr2(arr): " << arr2 << std::endl;

	arr[0] = 42;
	std::cout << "> arr[0] = 42" << std::endl << std::endl;
	arr[1] = 32;
	std::cout << "> arr[1] = 32" << std::endl << std::endl;

	std::cout << "arr(5): " << arr;
	std::cout << "arr2(arr): " << arr2 << std::endl;

	arr2[0] = 200;
	std::cout << "> arr2[0] = 200" << std::endl << std::endl;
	
	std::cout << "arr(5): " << arr;
	std::cout << "arr2(arr): " << arr2 << std::endl;

	arr2 = arr;
	std::cout << "> arr2 = arr" << std::endl << std::endl;

	std::cout << "arr(5): " << arr;
	std::cout << "arr2(arr): " << arr2 << std::endl;

	arr2[2] = 43;
	std::cout << "> arr2[2] = 43" << std::endl << std::endl;
	
	std::cout << "arr(5): " << arr;
	std::cout << "arr2(arr): " << arr2 << std::endl;
	return (0);
}


/*
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    	{
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/
