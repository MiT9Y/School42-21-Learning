/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:34:29 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 17:29:33 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int	main(void)
{
	{
		Array<int> numbers(10);

		std::cout << numbers[0] << std::endl;
		numbers[0] = 100;
		std::cout << numbers[0] << std::endl;
		const unsigned int &s = numbers.size();
		std::cout << s << std::endl;

		Array<int> a1;
	}
	{
		std::cout << std::endl << "***" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		Array<int> tmp = numbers;
		Array<int> test(tmp);

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

		std::cout << mirror[0] << ", " << numbers[0] << ", " << tmp[0] << ", " << test[0] << ", " << std::endl;
		tmp[0] = 1;
		test[0] = 2;
		std::cout << mirror[0] << ", " << numbers[0] << ", " << tmp[0] << ", " << test[0] << ", " << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		std::cout << mirror[0] << ", " << numbers[0] << ", " << tmp[0] << ", " << test[0] << ", " << std::endl;
		delete [] mirror;
	}
}