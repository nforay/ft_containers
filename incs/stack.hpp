/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:33:24 by nforay            #+#    #+#             */
/*   Updated: 2021/07/07 23:41:46 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "list.hpp"

namespace ft
{
	/**
	 * @brief Stacks are a type of container adaptor, specifically designed to
	 * operate in a LIFO context (last-in first-out), where elements are
	 * inserted and extracted only from one end of the container. Stacks are
	 * implemented as container adaptors, which are classes that use an
	 * encapsulated object of a specific container class as its underlying
	 * container, providing a specific set of member functions to access its
	 * elements. Elements are pushed/popped from the "back" of the specific
	 * container, which is known as the top of the stack.
	 * @tparam T Type of the elements.
	 * @tparam Container Type of the internal underlying container object where
	 * the elements are stored.
	*/
	template <class T, class Container = list<T> >
	class stack
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			/*  Maintainers wondering why this isn't uglified as per style
			*  guidelines should note that this name is specified in the standard,
			*  C++98 [23.2.3.1].
			*  (Why? Presumably for the same reason that it's protected instead
			*  of private: to allow derivation.  But none of the other
			*  containers allow for derivation.  Odd.)
			*/
			///  @c c is the underlying container.
			container_type		c;

		public:

			/**
			 * @brief Constructs a stack container adaptor object. A container
			 * adaptor keeps internally a container object as data. This
			 * container object is a copy of the ctnr argument passed to the
			 * constructor, if any, otherwise it is an empty container.
			 * @param ctnr Container object.
			*/
			explicit stack(const container_type& ctnr = container_type())
			: c(ctnr) {}

			/**
			 * @brief Copy constructor: Constructs a container with a copy of
			 * each of the elements in x.
			 * @param x Another stack object of the same type (with the same
			 * class template arguments T and Container), whose
			 * contents are either copied or acquired.
			*/
			stack(const stack& x) : c(x.c) {}

			~stack() {}

			/**
			 * @brief Copies all the elements from x into the container,
			 * changing its size accordingly.
			 * @return *this
			*/
			stack& operator=(const stack& x)
			{
				stack tmp(x);
				swap(c, tmp.c);
				return *this;
			}

			/**
			 * @brief Returns whether the stack is empty: i.e. whether its size
			 * is zero.
			 * @return true if the underlying container's size is 0, false
			 * otherwise.
			*/
			bool empty() const
			{
				return (c.empty());
			}

			/**
			 * @brief Returns the number of elements in the stack.
			 * @return The number of elements in the underlying container.
			*/
			size_type size() const
			{
				return (c.size());
			}

			/**
			 * @brief Returns a reference to the top element in the stack. Since
			 * stacks are last-in first-out containers, the top element is the
			 * last element inserted into the stack.
			 * @return A reference to the top element in the stack.
			*/
			value_type& top()
			{
				return(c.back());
			}

			/**
			 * @brief Returns a const reference to the top element in the stack.
			 * Since stacks are last-in first-out containers, the top element is
			 * the last element inserted into the stack.
			 * @return A const reference to the top element in the stack.
			*/
			const value_type& top() const
			{
				return(c.back());
			}

			/**
			 * @brief Inserts a new element at the top of the stack, above its
			 * current top element. The content of this new element is
			 * initialized to a copy of val.
			*/
			void push(const value_type& val)
			{
				c.push_back(val);
			}

			/**
			 * @brief Removes the element on top of the stack, effectively
			 * reducing its size by one.
			*/
			void pop()
			{
				c.pop_back();
			}

			friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c == rhs.c);
			}

			friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs.c < rhs.c);
			}
	};

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif /* ********************************************************* STACK_HPP */