/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:07:15 by msimon            #+#    #+#             */
/*   Updated: 2022/01/09 11:58:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Pbook.hpp"

int main(void)
{
	std::string	cmd;
	Pbook		pbook;
	int			index;
	std::string	sindex;
	
	std::cout << std::endl << "*** Welcome to the phonebook. Use the commands 'ADD', 'SEARCH', or 'EXIT' to manipulate it. ***" << std::endl << std::endl;

	while (1)
	{
		std::cout << "Enter your command: ";
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT"))
			break ;
		else if (!cmd.compare("ADD"))
			pbook.add();
		else if (!cmd.compare("SEARCH"))
		{
			if (pbook.show_contacts())
			{
				index = 0;
				std::cout << "Enter the index of the desired: ";
				while (!index)
				{
					std::getline(std::cin, sindex);
					index = pbook.show_contact(std::atoi(sindex.c_str()));
					if (!index)
						std::cout << "The index entered is not correct. Try again: ";
				}
			}
		}
		else
			std::cout << "Invalid command '" << cmd << "'. Use the commands 'ADD', 'SEARCH', or 'EXIT' to manipulate the phonebook." << std::endl << std::endl;
	}
	return (0);
}