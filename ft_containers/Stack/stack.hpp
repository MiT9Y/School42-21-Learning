/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:15:45 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:47:05 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../Vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef typename Container::value_type	value_type;
			typedef Container						container_type;
			typedef typename Container::size_type	size_type;
	
			explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
			~stack(){}

			bool				empty() const { return c.empty();}
			size_type			size() const {return (c.size());}
			value_type&			top() {return (*(c.end() - 1));}
			const value_type&	top() const {return (*(c.end() - 1));}
			void 				push(const value_type& val) {c.push_back(val);}
			void 				pop() {c.pop_back();}

		protected:
			container_type c;

		template <class U, class Cont>
		friend bool operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
		
		template <class U, class Cont>
		friend bool operator<  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c == rhs.c); }

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs == rhs); }
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (lhs.c < rhs.c); }

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs > rhs); }

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return (rhs < lhs);}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return !(lhs < rhs);}

}

#endif