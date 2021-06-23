/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by nforay            #+#    #+#             */
/*   Updated: 2021/06/23 16:59:11 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATORS_HPP
# define LIST_ITERATORS_HPP

# include <stddef.h>

namespace ft
{
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

			List_iterator(NodePtr node = nullptr) : m_node(node) {}
			List_iterator(const List_iterator<T, Node>& from)
			: m_node(from.m_node) {}
			~List_iterator() {}

			NodePtr	getNode() const { return m_node; }
			List_iterator& operator=(const List_iterator& it)
			{
				m_node = it.m_node;
				return *this;
			}

			bool operator==(const List_iterator<T, Node>& it) const
			{
				return m_node == it.m_node;
			}
			bool operator!=(const List_iterator<T, Node>& it) const
			{
				return m_node != it.m_node;
			}
			reference operator*() const { return m_node->val; }
			pointer operator->() const { return &(m_node->val); }
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
	class List_const_iterator : public List_iterator<T, Node>
	{
		public:

			typedef T const &	const_reference;
			typedef T const *	const_pointer;
			typedef Node*		NodePtr;

			List_const_iterator(NodePtr node)
			{
				this->m_node = node;
			}
			List_const_iterator& operator=(const List_const_iterator<T, Node>& it)
			{
				this->m_node = it.m_node;
				return *this;
			}

			const_reference operator*() const { return this->m_node->val; }
			const_pointer operator->() const { return &(this->m_node->val); }
	};
	
	template<class T, typename Node>
	class List_reverse_iterator
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

			List_reverse_iterator(NodePtr node = nullptr) : m_node(node) {}
			List_reverse_iterator(const List_reverse_iterator<T, Node>& from)
			: m_node(from.m_node) {}
			~List_reverse_iterator() {}

			List_reverse_iterator& operator=(const List_reverse_iterator<T, Node>& it)
			{
				m_node = it.m_node;
				return *this;
			}

			bool operator==(const List_reverse_iterator<T, Node>& it) const
			{
				return m_node == it.m_node;
			}
			bool operator!=(const List_reverse_iterator<T, Node>& it) const
			{
				return m_node != it.m_node;
			}
			reference operator*() const { return m_node->val; }
			pointer operator->() const { return &(m_node->val); }
			List_reverse_iterator operator++()
			{
				m_node = m_node->prev;
				return *this;
			}
			List_reverse_iterator operator++(int)
			{
				List_reverse_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			List_reverse_iterator operator--()
			{
				m_node = m_node->next;
				return *this;
			}
			List_reverse_iterator operator--(int)
			{
				List_reverse_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class T, typename Node>
	class List_const_reverse_iterator : public List_reverse_iterator<T, Node>
	{
		public:

			typedef T const &	const_reference;
			typedef T const *	const_pointer;
			typedef Node*		NodePtr;

			List_const_reverse_iterator(NodePtr node)
			{
				this->m_node = node;
			}
			List_const_reverse_iterator& operator=(const List_const_reverse_iterator<T, Node>& it)
			{
				this->m_node = it.m_node;
				return *this;
			}

			const_reference operator*() const { return this->m_node->val; }
			const_pointer operator->() const { return &(this->m_node->val); }
	};
}

#endif /* ************************************************ LIST_ITERATORS_HPP */