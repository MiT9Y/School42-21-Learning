/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FourTypes.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:24:44 by msimon            #+#    #+#             */
/*   Updated: 2022/02/01 20:47:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FourTypes.hpp"

FourTypes::FourTypes(char val)
{
	_charVal = val;
	_intVal = static_cast<int>(val);
	_floatVal = static_cast<float>(val);
	_doubleVal = static_cast<double>(val);
	_overflowChar = false;
	_overflowInt = false;
}

FourTypes::FourTypes(int val)
{
	_charVal = static_cast<char>(val);
	_intVal = val;
	_floatVal = static_cast<float>(val);
	_doubleVal = static_cast<double>(val);
	if (val > static_cast<int>(std::numeric_limits<char>::max())
		|| val < static_cast<int>(std::numeric_limits<char>::min()))
		_overflowChar = true;
	else
		_overflowChar = false;
	_overflowInt = false;
}

FourTypes::FourTypes(float val)
{
	_charVal = static_cast<char>(val);
	_intVal = static_cast<int>(val);
	_floatVal = val;
	_doubleVal = static_cast<double>(val);
	if ((val == val)
		&& (val != std::numeric_limits<float>::infinity())
		&& (val != -std::numeric_limits<float>::infinity())
		&& (val <= static_cast<float>(std::numeric_limits<int>::max()))
		&& (val >= static_cast<float>(std::numeric_limits<int>::min())))
		_overflowInt = false;
	else
		_overflowInt = true;
	if (!_overflowInt
		&& (val <= static_cast<float>(std::numeric_limits<char>::max()))
		&& (val >= static_cast<float>(std::numeric_limits<char>::min())))
		_overflowChar = false;
	else
		_overflowChar = true;
}

FourTypes::FourTypes(double val)
{
	_charVal = static_cast<char>(val);
	_intVal = static_cast<int>(val);
	_floatVal = static_cast<float>(val);
	_doubleVal = val;
	if ((val == val)
		&& (val != std::numeric_limits<double>::infinity())
		&& (val != -std::numeric_limits<double>::infinity())
		&& (val <= static_cast<double>(std::numeric_limits<int>::max()))
		&& (val >= static_cast<double>(std::numeric_limits<int>::min())))
		_overflowInt = false;
	else
		_overflowInt = true;
	if (!_overflowInt
		&& (val <= static_cast<double>(std::numeric_limits<char>::max()))
		&& (val >= static_cast<double>(std::numeric_limits<char>::min())))
		_overflowChar = false;
	else
		_overflowChar = true;
}

FourTypes::FourTypes(const FourTypes &obj)
{
	*this = obj;
}

FourTypes::~FourTypes(void)
{
	return ;
}

FourTypes	&FourTypes::operator=(const FourTypes &obj)
{
	if (this != &obj)
	{
		_charVal = obj._charVal;
		_intVal = obj._intVal;
		_floatVal = obj._floatVal;
		_doubleVal = obj._doubleVal;
		_overflowChar = obj._overflowChar;
		_overflowInt = obj._overflowInt;
	}
	return (*this);
}

void	FourTypes::printChar(void)
{
	std::cout << "char: ";
	if (_overflowChar)
		std::cout << "impossible" << std::endl;
	else if (_charVal < ' ' || _charVal > '~')
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << std::string(1, _charVal) << "'" << std::endl;
}

void	FourTypes::printInt(void)
{
	std::cout << "int: ";
	if (_overflowInt)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _intVal << std::endl;
}

void	FourTypes::printFloat(void)
{
	std::cout << "float: " << _floatVal;
	if (_floatVal - static_cast<int>(_floatVal) == 0.0)
		std::cout << ".0";
	std::cout << 'f' << std::endl;
}

void	FourTypes::printDouble(void)
{
	std::cout << "double: " << _doubleVal;
	if (_doubleVal - static_cast<int>(_doubleVal) == 0.0)
		std::cout << ".0";
	std::cout << std::endl;
}

int	FourTypes::getType(char *str)
{
	int	i = 0;
	int	r_type = 1;

	if ((!str[1] && (str[0] < '0' || str[0] > '9'))
		|| (!str[3] && str[0] == '\'' && str[2] == '\''))
		return (0);
	if (std::string(str) == std::string("nanf")
		|| std::string(str) == std::string("+inff")
		|| std::string(str) == std::string("-inff"))
		return (2);
	if (std::string(str) == std::string("nan")
		|| std::string(str) == std::string("+inf")
		|| std::string(str) == std::string("-inf"))
		return (3);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '.' && r_type == 1)
				r_type = 3;
			else if (r_type == 3 && str[i] == 'f' && !str[i + 1])
				r_type = 2;
			else
				return (4);
		}
		i++;
	}
	return (r_type);
}

char	FourTypes::getCharValue(char *str)
{
	if (!str[1])
		return (str[0]);
	else
		return (str[1]);
}

int		FourTypes::getIntValue(char *str)
{
	return (std::atoi(str));
}

float	FourTypes::getFloatValue(char *str)
{
	return (static_cast<float>(std::atof(str)));
}

double	FourTypes::getDoubleValue(char *str)
{
	return (std::atof(str));
}
