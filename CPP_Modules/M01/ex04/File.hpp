/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:32:19 by msimon            #+#    #+#             */
/*   Updated: 2022/01/14 15:03:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>

class	File
{
	public:
		bool	open_and_read(std::string path);
		bool	replace(std::string s1, std::string s2);
		bool	write_and_reset(std::string path = "");

	private:
		std::string	_content;
		std::string	_path;
};

#endif