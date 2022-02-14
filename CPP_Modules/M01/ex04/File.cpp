/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:22:01 by msimon            #+#    #+#             */
/*   Updated: 2022/01/14 15:03:49 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

bool	File::open_and_read(std::string path)
{
	std::ifstream	r_file;

	r_file.open(path);
	if (!r_file.is_open())
	{
		std::cerr << "ERROR: File - " << path << " not is open to read\n";
		return (false);
	}
	this->_path = path;
	std::getline(r_file, this->_content, '\0');
	r_file.close();
	return (true);
}

bool	File::replace(std::string s1, std::string s2)
{
	size_t	pos;
	
	if (s1.empty() || s2.empty())
	{
		std::cerr << "ERROR: source and destination strings must NOT be empty\n";
		return (false);
	}
	pos = -1;
	while (++pos < this->_content.length())
	{
		if (this->_content.compare(pos, s1.length(), s1) == 0)
		{
			this->_content.erase(pos, s1.length());
			this->_content.insert(pos, s2);
		}
	}
	return (true);
}

bool	File::write_and_reset(std::string path)
{
	std::ofstream	w_file;

	if (path.empty())
		path = this->_path;
	w_file.open(path);
	if (!w_file.is_open())
	{
		std::cerr << "ERROR: File - " << path << " not is open to write\n";
		return (false);
	}
	w_file << this->_content;
	w_file.close();
	this->_content = "";
	this->_path = "";
	return (true);
}
