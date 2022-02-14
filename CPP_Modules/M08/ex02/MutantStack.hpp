/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 07:56:02 by msimon            #+#    #+#             */
/*   Updated: 2022/02/06 08:14:24 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class	MutantStack: public std::stack <T>
{
	public:
		MutantStack <T>(void) {}
		MutantStack <T>(const MutantStack<T> &obj) {*this = obj;}
		~MutantStack <T>(void) {}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin(void)
		{
			return (this->c.begin());
		}
		iterator end(void)
		{
			return (this->c.end());
		}
};

#endif
