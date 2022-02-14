/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pbook.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:47:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/11 10:41:14 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pbook.hpp"

int	Pbook::_count = 0;

void	Pbook::add(void)
{
	int			i;
	std::string	buf;

	i = get_contact_index();
	std::cout << "Enter data of the new contact" << std::endl;
	std::cout << "Write first name: ";
	std::getline(std::cin, buf);
	contacts[i].set_value(buf, std::string("firstname"));
	std::cout << "Write last name: ";
	std::getline(std::cin, buf);
	contacts[i].set_value(buf, std::string("lastname"));
	std::cout << "Write nickname: ";
	std::getline(std::cin, buf);
	contacts[i].set_value(buf, std::string("nickname"));
	std::cout << "Write phone number: ";
	std::getline(std::cin, buf);
	contacts[i].set_value(buf, std::string("phonenumber"));
	std::cout << "Write darkest secret: ";
	std::getline(std::cin, buf);
	contacts[i].set_value(buf, std::string("darkestsecret"));
	std::cout << std::endl;
	return ;
}

int	Pbook::get_contact_index(void)
{
	int	i;

	if (_count < 8)
		_count++;
	else
	{
		i = 0;
		while (++i < _count)
			contacts[i - 1] = contacts[i];
	}
	return (_count - 1);
}

int	Pbook::show_contacts(void)
{
	int	i;

	std::cout << std::endl << "CONTACT LIST" << std::endl;
	if (!_count)
		std::cout << "list is empty" << std::endl << std::endl;
	else
	{
		std::cout << '|' << std::setfill(' ') << std::setw(10) << "index" << '|';
		std::cout << std::setfill(' ') << std::setw(10) << "first name" << '|';
		std::cout << std::setfill(' ') << std::setw(10) << "last name" << '|';
		std::cout << std::setfill(' ') << std::setw(10) << "nickname" << '|' << std::endl;
		i = -1;
		while (++i < _count)
		{
			std::cout << '|' << std::setfill(' ') << std::setw(10) << (i + 1) << '|';
			std::cout << std::setfill(' ') << std::setw(10) << contacts[i].get_small_value(std::string("firstname")) << '|';
			std::cout << std::setfill(' ') << std::setw(10) << contacts[i].get_small_value(std::string("lastname")) << '|';
			std::cout << std::setfill(' ') << std::setw(10) << contacts[i].get_small_value(std::string("nickname")) << '|' << std::endl;
		}
		std::cout << std::endl;
		return (1);
	}
	return (0);
}

int	Pbook::show_contact(int index)
{
	index -= 1;
	if (index >= 0 && index < _count)
	{
		std::cout << std::endl << "CONTACT INFORMATION" << std::endl;
		std::cout << "First name: " << contacts[index].get_value(std::string("firstname")) << std::endl;
		std::cout << "Last name: " << contacts[index].get_value(std::string("lastname")) << std::endl;
		std::cout << "Nickname: " << contacts[index].get_value(std::string("nickname")) << std::endl;
		std::cout << "Phone number: " << contacts[index].get_value(std::string("phonenumber")) << std::endl;
		std::cout << "Darkest secret: " << contacts[index].get_value(std::string("darkestsecret")) << std::endl;
		std::cout << std::endl;
		return (1);
	}
	return (0);
}
