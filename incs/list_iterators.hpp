/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by nforay            #+#    #+#             */
/*   Updated: 2021/06/28 15:55:03 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ITERATORS_HPP
# define LIST_ITERATORS_HPP

# include <stddef.h>

namespace ft
{
	template<class T, typename Node> class List_const_iterator;

	template<class T, typename Node>
	class List_iterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef Node*							NodePtr;

		protected:

			NodePtr	m_node;

		private:

			List_iterator(const List_const_iterator<T, Node>& ) {}

		public:

			List_iterator(NodePtr node = NULL) : m_node(node) {}
			List_iterator(const List_iterator& from) : m_node(from.m_node) {}
			~List_iterator() {}

			NodePtr	getNode() const { return m_node; }
			List_iterator& operator=(const List_iterator& it)
			{
				if (this != &it)
					m_node = it.m_node;
				return (*this);
			}

			bool operator==(const List_iterator& it) const
			{
				return (m_node == it.m_node);
			}
			bool operator!=(const List_iterator& it) const
			{
				return (m_node != it.m_node);
			}
			reference operator*() const { return (m_node->val); }
			pointer operator->() const { return (&(m_node->val)); }
			List_iterator& operator++()
			{
				m_node = m_node->next;
				return (*this);
			}
			List_iterator operator++(int)
			{
				List_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			List_iterator& operator--()
			{
				m_node = m_node->prev;
				return (*this);
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
			List_const_iterator(const List_iterator<T, Node>& from)
			{
				this->m_node = from.getNode();
			}

			List_const_iterator& operator=(const List_const_iterator& it)
			{
				if (this != &it) 
					this->m_node = it.m_node;
				return (*this);
			}
			const_reference operator*() const { return (this->m_node->val); }
			const_pointer operator->() const { return (&(this->m_node->val)); }
	};
	
	template<class T, typename Node> class List_const_reverse_iterator;

	template<class T, typename Node>
	class List_reverse_iterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;
			typedef Node*							NodePtr;

		protected:

			List_iterator<T, Node>		m_base;

		private:

			List_reverse_iterator(const List_const_reverse_iterator<T, Node>& ) {}

		public:

			List_reverse_iterator(NodePtr node = NULL)
			: m_base(List_iterator<T, Node>(node)) {}
			explicit List_reverse_iterator(List_iterator<T, Node> from)
			: m_base(from.getNode()->prev) {}
			List_reverse_iterator(const List_reverse_iterator<T, Node>& rev_it)
			: m_base(rev_it.m_base) {}

			NodePtr	getNode() const { return (this->m_base.getNode()); }
			List_iterator<T, Node> base() const
			{
				return (this->m_base.getNode()->next);
			}
			List_reverse_iterator& operator=(const List_reverse_iterator& it)
			{
				if (this != &it)
					m_base = it.m_base;
				return (*this);
			}
			bool operator==(const List_reverse_iterator& it) const
			{
				return (m_base == it.m_base);
			}
			bool operator!=(const List_reverse_iterator& it) const
			{
				return (m_base != it.m_base);
			}
			reference operator*() const
			{
				return (*(List_iterator<T, Node>(this->m_base)));
			}
			pointer operator->() const
			{
				return (&this->operator*());
			}
			List_reverse_iterator& operator++()
			{
				this->m_base.operator--();
				return (*this);
			}
			List_reverse_iterator operator++(int)
			{
				List_reverse_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			List_reverse_iterator& operator--()
			{
				this->m_base.operator++();
				return (*this);
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

			explicit List_const_reverse_iterator(List_iterator<T, Node> from)
			{
				this->m_base = from.getNode()->prev;
			}
			List_const_reverse_iterator(List_const_iterator<T, Node> from)
			{
				this->m_base = from.getNode()->prev;
			}
			List_const_reverse_iterator(const List_reverse_iterator<T, Node>& from)
			{
				this->m_base = from.getNode();
			}

			List_const_reverse_iterator& operator=(const List_const_reverse_iterator& it)
			{
				if (this != &it) 
					this->m_base = it.m_base;
				return (*this);
			}
			bool operator==(const List_const_reverse_iterator& it) const
			{
				return (this->m_base == it.m_base);
			}
			bool operator!=(const List_const_reverse_iterator& it) const
			{
				return (this->m_base != it.m_base);
			}
			const_reference operator*() const
			{
				return (*(List_iterator<T, Node>(this->m_base)));
			}
			const_pointer operator->() const { return (&this->operator*()); }
	};
}

#endif /* ************************************************ LIST_ITERATORS_HPP */