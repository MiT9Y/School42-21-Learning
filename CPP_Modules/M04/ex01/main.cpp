/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:28:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/26 11:54:53 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	{
		std::cout << "*** TEST 1 ***" << std::endl;
		Brain	br1;
		br1.get_ideas()[0] = "AAA";
		Brain	br2(br1);
		br1.get_ideas()[1] = "BBB";
		br2.get_ideas()[1] = "ZZZ";
		Brain	br3;
		br3 = br1;
		br3.get_ideas()[2] = "WWW";

		std::cout << br1.get_ideas()[0] << ", " << br1.get_ideas()[1] << ", " << br1.get_ideas()[2] << ", " << br1.get_ideas()[3] << ", " << std::endl;
		std::cout << br2.get_ideas()[0] << ", " << br2.get_ideas()[1] << ", " << br2.get_ideas()[2] << ", " << br2.get_ideas()[3] << ", " << std::endl;
		std::cout << br3.get_ideas()[0] << ", " << br3.get_ideas()[1] << ", " << br3.get_ideas()[2] << ", " << br3.get_ideas()[3] << ", " << std::endl;
	}
	{
		std::cout << "*** TEST 2 ***" << std::endl;
		Cat	cat;

		std::cout << cat <<std::endl;
		std::cout << cat.get_brain()->get_idea(0) << ", " << cat.get_brain()->get_idea(1) << std::endl;
	}
	{
		std::cout << "*** TEST 3 ***" << std::endl;		
		const int	n = 3;
		int			i;
		Animal		*arr_animals[n];

		i = -1;
		while (++i < n / 2)
			arr_animals[i] = new Dog;
		i--;
		while (++i < n)
			arr_animals[i] = new Cat;
		arr_animals[2]->get_brain()->get_ideas()[1] = "SLEEP";
		std::cout << arr_animals[1]->get_brain()->get_idea(1) << std::endl;
		*arr_animals[1] = *arr_animals[2];
		std::cout << arr_animals[1]->get_brain()->get_idea(1) << std::endl;
		std::cout << *arr_animals[0] << ". IDEA 0 - " << arr_animals[0]->get_brain()->get_idea(0) << std::endl;
		*arr_animals[0] = *arr_animals[2];
		std::cout << *arr_animals[0] << ". IDEA 0 - " << arr_animals[0]->get_brain()->get_idea(0) << std::endl;
		i = -1;
		while (++i < n)
			delete arr_animals[i];
	}
	return (0);
}
