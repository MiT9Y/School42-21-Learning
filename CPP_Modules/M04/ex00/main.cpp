/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:28:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:05:46 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "*** TEST 1 ***" << std::endl;
		Animal	an;
		Cat		cat;
		Animal	an2;
		an2 = cat;
		Animal	an3(cat);

		std::cout << an << std::endl;
		std::cout << cat << std::endl;
		std::cout << an2 << std::endl;
		std::cout << an3 << std::endl;
	}
	{
		std::cout << std::endl << "*** TEST 2 ***" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); std::cout << std::endl;
		j->makeSound(); std::cout << std::endl;
		meta->makeSound(); std::cout << std::endl;
		std::cout << *i << std::endl;
		std::cout << *j << std::endl;
		std::cout << *meta << std::endl;
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << std::endl << "*** TEST 3 ***" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); std::cout << std::endl;
		meta->makeSound(); std::cout << std::endl;
		std::cout << *i << std::endl;
		std::cout << *meta << std::endl;
		delete i;
		delete meta;
	}
	return (0);
}