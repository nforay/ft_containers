/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by nforay            #+#    #+#             */
/*   Updated: 2021/06/20 20:47:22 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATORS_HPP
# define LIST_ITERATORS_HPP

# include <stddef.h>

namespace ft
{
	template<class T, typename Node>
	class List_const_iterator;
	
	template<class T, typename Node>
	class List_iterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef Node*							NodePtr;

		protected:

			NodePtr	m_node;

		public:

			List_iterator() : m_node(nullptr) {}
			List_iterator(const List_iterator<T, Node>& from) : m_node(from.m_node) {}
			~List_iterator() {}

			List_iterator& operator=(const List_iterator& it)
			{
				m_node = it.m_node;
				return *this;
			}

			bool operator==(const List_iterator& it) const {return m_node == it.m_node;}
			bool operator!=(const List_iterator& it) const {return m_node != it.m_node;}
			reference operator*() const { return m_node->val;}
			pointer operator->() const { return &(node->val);}
			List_iterator operator++()
			{
				m_node = m_node->next;
				return *this;
			}
			List_iterator operator++(int)
			{
				List_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			List_iterator operator--()
			{
				m_node = m_node->prev;
				return *this;
			}
			List_iterator operator--(int)
			{
				List_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class T, typename Node>
	class List_const_reverse_iterator;
	
	template<class T, typename Node>
	class List_reverse_iterator
	{
		public:

			typedef T				value_type;
			typedef ptrdiff_t		difference_type;
			typedef value_type*		pointer;
			typedef value_type&		reference;
	};
}

#endif /* ************************************************ LIST_ITERATORS_HPP */