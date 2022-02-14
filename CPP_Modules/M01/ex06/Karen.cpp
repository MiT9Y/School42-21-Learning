/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:28:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/16 11:58:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

Karen::Karen( void )
{
	_allow_level = 0;
	_arr_messeges[0] = "DEBUG";
	_arr_functions[0] = &Karen::debug;
	_arr_messeges[1] = "INFO";
	_arr_functions[1] = &Karen::info;
	_arr_messeges[2] = "WARNING";
	_arr_functions[2] = &Karen::warning;
	_arr_messeges[3] = "ERROR";
	_arr_functions[3] = &Karen::error;
	_arr_functions[4] = &Karen::other;
}

void	Karen::complain(std::string level)
{
	int	lvl_index;
	
	lvl_index = get_level_index(level);
	switch ((int)(lvl_index >=_allow_level))
	{
		case 1:
			(this->*_arr_functions[lvl_index])();
			break;
	}
}

int	Karen::get_level_index(std::string level)
{
	int	i;

	i = -1;
	while(++i < MESSEGES_ARR_LEN)
		if (!_arr_messeges[i].compare(level))
			return (i);
	return (i);
}

void	Karen::debug(void)
{
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-"
		<< "special-ketchup burger. I just love it!\n"
		<< std::endl;
}

void	Karen::info(void)
{
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon cost more money. You don’t put "
		<< "enough! If you did I would not have to ask for it!\n"
		<< std::endl;
}

void	Karen::warning(void)
{
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free. I’ve been coming"
		<< " here for years and you just started working here last month.\n"
		<< std::endl;
}

void	Karen::error(void)
{
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now.\n"
		<< std::endl;
}

void	Karen::other(void)
{
	return ;
}

void	Karen::set_allow_level(std::string level)
{
	_allow_level = get_level_index(level);
	if (_allow_level == MESSEGES_ARR_LEN)
		std::cout
			<< "[ Probably complaining about insignificant problems ]"
			<< std::endl;
}
