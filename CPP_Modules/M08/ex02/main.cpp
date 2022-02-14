/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 08:00:23 by msimon            #+#    #+#             */
/*   Updated: 2022/02/06 08:26:32 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(-2131);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;
	std::cout << s.size() << std::endl;

	MutantStack<int> ms(mstack);
	ite = --ms.end();
	std::cout << *ite << std::endl;
	ms.push(23423);
	ms.push(4234);
	std::cout << *ite << std::endl;
	ite = --ms.end();
	ite--;
	*ite = 333;
	std::cout << ms.top() << std::endl;
	ms.pop();
	std::cout << ms.top() << std::endl;
	return 0;
}
