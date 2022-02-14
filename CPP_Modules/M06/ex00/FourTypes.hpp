/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FourTypes.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:46:37 by msimon            #+#    #+#             */
/*   Updated: 2022/02/01 20:41:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOURTYPES_HPP
# define FOURTYPES_HPP

# include <iostream>

class	FourTypes
{
	public:
		FourTypes(char val);
		FourTypes(int val);
		FourTypes(float val);
		FourTypes(double val);
		FourTypes(const FourTypes &obj);
		~FourTypes(void);

		FourTypes	&operator=(const FourTypes &obj);
	
		void			printChar(void);
		void			printInt(void);
		void			printFloat(void);
		void			printDouble(void);
		static int		getType(char *str);
		static char		getCharValue(char *str);
		static int		getIntValue(char *str);
		static float	getFloatValue(char *str);
		static double	getDoubleValue(char *str);

	private:
		FourTypes(void);

		char	_charVal;
		int		_intVal;
		float	_floatVal;
		double	_doubleVal;
		bool	_overflowChar;
		bool	_overflowInt;
};

#endif
