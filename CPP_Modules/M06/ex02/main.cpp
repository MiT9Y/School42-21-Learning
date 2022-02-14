/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:09:59 by msimon            #+#    #+#             */
/*   Updated: 2022/02/02 16:53:58 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generate class A" << std::endl;
			return (new A);
		case 1:
			std::cout << "Generate class B" << std::endl;
			return (new B);
		case 2:
			std::cout << "Generate class C" << std::endl;
			return (new C);
	}
	return (new Base);
}

void	identify(Base *ptr)
{
	std::cout << "Identify PTR" << std::endl;
	if (dynamic_cast<A *>(ptr))
		std::cout << "Class - A" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "Class - B" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "Class - C" << std::endl;
	return ;
}

void	identify(Base &ref)
{
	std::cout << "Identify REF" << std::endl;
	try
	{
		A	&a = dynamic_cast<A &>(ref);
		(void) a;
		std::cout << "Class - A" << std::endl;
		return ;
	}
	catch (...)
	{ }
	try
	{
		B	&b = dynamic_cast<B &>(ref);
		(void) b;
		std::cout << "Class - B" << std::endl;
		return ;

	}
	catch (...)
	{ }
	try
	{
		C	&c = dynamic_cast<C &>(ref);
		(void) c;
		std::cout << "Class - C" << std::endl;
		return ;
	}
	catch (...)
	{ }

}

int	main(void)
{
	Base*	obj_ptr;
	int		i;
	int		count = 10;

	std::srand(std::time(NULL));
	i = -1;
	while (++i < count)
	{
		obj_ptr = generate();
		identify(obj_ptr);
		delete obj_ptr;
	}
	std::cout << std::endl;
	i = -1;
	while (++i < count)
	{
		obj_ptr = generate();
		identify(*obj_ptr);
		delete obj_ptr;
	}
	return (0);
}
