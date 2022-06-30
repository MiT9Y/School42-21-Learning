/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsIntegral.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:53:59 by msimon            #+#    #+#             */
/*   Updated: 2022/05/15 14:20:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
# define ISINTEGRAL_HPP

namespace ft
{

	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() const { return v; }
	};
	
	template <class T>	struct is_integral
		: public integral_constant<bool, false> {};

	template <>	struct is_integral<bool>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<char>
		: public integral_constant<bool, true> {};
		
	template <>	struct is_integral<char16_t>
		: public integral_constant<bool, true> {};

	template <> struct is_integral<char32_t>
		: public integral_constant<bool, true> {};
		
	template <> struct is_integral<wchar_t>
		: public integral_constant<bool, true> {};

	template <> struct is_integral<signed char>
		: public integral_constant<bool, true> {};
		
	template <> struct is_integral<short int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<long int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<long long int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<unsigned char>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<unsigned short int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<unsigned int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<unsigned long int>
		: public integral_constant<bool, true> {};

	template <>	struct is_integral<unsigned long long int>
		: public integral_constant<bool, true> {};

}

#endif