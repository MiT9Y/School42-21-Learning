/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:13:59 by msimon            #+#    #+#             */
/*   Updated: 2022/01/10 21:42:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_value(std::string val, std::string field_name)
{
	if (!field_name.compare("firstname"))
		firstname = val;
	else if (!field_name.compare("lastname"))
		lastname = val;
	else if (!field_name.compare("nickname"))
		nickname = val;
	else if (!field_name.compare("phonenumber"))
		phonenumber = val;
	else if (!field_name.compare("darkestsecret"))
		darkestsecret = val;
	return ;
}

std::string	Contact::get_value(std::string field_name)
{
	if (!field_name.compare("firstname"))
		return firstname;
	else if (!field_name.compare("lastname"))
		return lastname;
	else if (!field_name.compare("nickname"))
		return nickname;
	else if (!field_name.compare("phonenumber"))
		return phonenumber;
	else if (!field_name.compare("darkestsecret"))
		return darkestsecret;
	return (std::string(""));
}

std::string	Contact::get_small_value(std::string field_name)
{
	std::string	res;

	res = get_value(field_name);
	if (res.length() > 10)
		res = res.substr(0, 9) + '.';
	return (res);
}
