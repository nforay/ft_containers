/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 19:28:07 by nforay            #+#    #+#             */
/*   Updated: 2021/07/07 04:21:07 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATORS_HPP
# define VECTOR_ITERATORS_HPP

# include <stddef.h>

namespace ft
{
	template<class T> class Vector_const_iterator;

	template<class T>
	class Vector_iterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		protected:

			pointer	m_ptr;

		private:

			Vector_iterator(const Vector_const_iterator<T>& ) {}

		public:

			Vector_iterator(pointer ptr = NULL) : m_ptr(ptr) {}
			Vector_iterator(const Vector_iterator& from) : m_ptr(from.m_ptr) {}
			~Vector_iterator() {}

			Vector_iterator& operator=(const Vector_iterator& it)
			{
				if (this != &it)
					m_ptr = it.m_ptr;
				return (*this);
			}

			bool operator==(const Vector_iterator& it) const
			{
				return (m_ptr == it.m_ptr);
			}
			bool operator!=(const Vector_iterator& it) const
			{
				return (m_ptr != it.m_ptr);
			}
			reference operator*() const { return (*m_ptr); }
			reference operator[](size_t n) { return m_ptr[n]; }
			pointer operator->() const { return (m_ptr); }
			Vector_iterator& operator++()
			{
				m_ptr++;
				return (*this);
			}
			Vector_iterator operator++(int)
			{
				Vector_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			Vector_iterator& operator--()
			{
				m_ptr--;
				return (*this);
			}
			Vector_iterator operator--(int)
			{
				Vector_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
			Vector_iterator operator+(difference_type n) const
			{
				return (Vector_iterator(m_ptr + n));
			}
			Vector_iterator operator-(difference_type n) const
			{
				return (Vector_iterator(m_ptr - n));
			}
			difference_type operator-(const Vector_iterator& other) const
			{
				return (m_ptr - other.m_ptr);
			}
			friend Vector_iterator operator+(difference_type n, const Vector_iterator& other)
			{
				return (other.operator+(n));
			}
			difference_type operator+(const Vector_iterator& other) const
			{
				return (m_ptr + other.m_ptr);
			}
			Vector_iterator& operator+=(int n)
			{
				m_ptr += n;
				return (*this);
			}
			Vector_iterator& operator-=(int n)
			{
				m_ptr -= n;
				return (*this);
			}
			bool operator<(const Vector_iterator& other) const
			{
				return (m_ptr < other.m_ptr);
			}
			bool operator>(const Vector_iterator& other) const
			{
				return (m_ptr > other.m_ptr);
			}
			bool operator<=(const Vector_iterator& other) const
			{
				return (m_ptr <= other.m_ptr);
			}
			bool operator>=(const Vector_iterator& other) const
			{
				return (m_ptr >= other.m_ptr);
			}
	};

	template<class T>
	class Vector_const_iterator : public Vector_iterator<T>
	{
		public:

			typedef T*			pointer;
			typedef T const &	const_reference;
			typedef T const *	const_pointer;

		private:
			const_reference operator[](size_t ) {return this->m_ptr; }
			
		public:

			Vector_const_iterator(pointer ptr = NULL)
			{
				this->m_ptr = ptr;
			}
			Vector_const_iterator(const Vector_iterator<T>& from)
			{
				this->m_ptr = from.operator->();
			}

			Vector_const_iterator& operator=(const Vector_const_iterator& it)
			{
				if (this != &it) 
					this->m_ptr = it.m_ptr;
				return (*this);
			}
			bool operator<(const Vector_const_iterator& other) const
			{
				return (this->m_ptr < other.m_ptr);
			}
			bool operator>(const Vector_const_iterator& other) const
			{
				return (this->m_ptr > other.m_ptr);
			}
			bool operator<=(const Vector_const_iterator& other) const
			{
				return (this->m_ptr <= other.m_ptr);
			}
			bool operator>=(const Vector_const_iterator& other) const
			{
				return (this->m_ptr >= other.m_ptr);
			}
			const_reference operator*() const { return (*this->m_ptr); }
			const_pointer operator->() const { return (this->m_ptr); }
	};
	
	template<class T> class Vector_const_reverse_iterator;

	template<class T>
	class Vector_reverse_iterator
	{
		public:

			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

		protected:

			Vector_iterator<T>						m_base;

		private:

			Vector_reverse_iterator(const Vector_const_reverse_iterator<T>& ) {}

		public:

			Vector_reverse_iterator(pointer ptr = NULL)
			: m_base(Vector_iterator<T>(ptr)) {}
			explicit Vector_reverse_iterator(Vector_iterator<T> from)
			: m_base(--from) {}
			Vector_reverse_iterator(const Vector_reverse_iterator<T>& rev_it)
			: m_base(rev_it.m_base) {}

			Vector_iterator<T> base() const
			{
				Vector_iterator<T> tmp(m_base);
				return (++tmp);
			}
			Vector_reverse_iterator& operator=(const Vector_reverse_iterator& it)
			{
				if (this != &it)
					m_base = it.m_base;
				return (*this);
			}
			bool operator==(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator==(rhs.m_base);
			}
			bool operator!=(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator!=(rhs.m_base);
			}
			bool operator<(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator>(rhs.m_base);
			}
			bool operator<=(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator>=(rhs.m_base);
			}
			bool operator>(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator<(rhs.m_base);
			}
			bool operator>=(const Vector_reverse_iterator& rhs) const
			{
				return this->m_base.operator<=(rhs.m_base);
			}
			reference operator[](size_t n) { return this->m_base.operator[](n); }
			reference operator*() const
			{
				return (*(Vector_iterator<T>(this->m_base)));
			}
			pointer operator->() const
			{
				return (&this->operator*());
			}
			friend Vector_reverse_iterator operator+(difference_type n, const Vector_reverse_iterator& other)
			{
				return (other.operator+(n));
			}
			Vector_reverse_iterator operator+(difference_type n) const
			{
				Vector_reverse_iterator tmp(*this);
				tmp.m_base.operator-=(n);
				return (tmp);
			}
			Vector_reverse_iterator operator-(difference_type n) const
			{
				Vector_reverse_iterator tmp(*this);
				tmp.m_base.operator+=(n);
				return (tmp);
			}
			difference_type operator-(const Vector_reverse_iterator& other)
			{
				return (other.base().operator-(this->m_base));
			}
			difference_type operator+(const Vector_reverse_iterator& other)
			{
				return (other.base().operator+(this->m_base));
			}
			Vector_reverse_iterator& operator+=(int n)
			{
				this->m_base.operator-=(n);
				return (*this);
			}
			Vector_reverse_iterator& operator-=(int n)
			{
				this->m_base.operator+=(n);
				return (*this);
			}
			Vector_reverse_iterator& operator++()
			{
				this->m_base.operator--();
				return (*this);
			}
			Vector_reverse_iterator operator++(int)
			{
				Vector_reverse_iterator tmp(*this);
				++(*this);
				return (tmp);
			}
			Vector_reverse_iterator& operator--()
			{
				this->m_base.operator++();
				return (*this);
			}
			Vector_reverse_iterator operator--(int)
			{
				Vector_reverse_iterator tmp(*this);
				--(*this);
				return (tmp);
			}
	};

	template<class T>
	class Vector_const_reverse_iterator : public Vector_reverse_iterator<T>
	{
		public:

			typedef T const &	const_reference;
			typedef T const *	const_pointer;
			typedef T*			pointer;

			explicit Vector_const_reverse_iterator(Vector_iterator<T> from)
			{
				Vector_iterator<T> tmp(from);
				this->m_base = --tmp;
			}
			Vector_const_reverse_iterator(pointer ptr = NULL)
			{
				this->m_base = Vector_iterator<T>(ptr);
			}
			Vector_const_reverse_iterator(Vector_const_iterator<T> from)
			{
				pointer ptr = const_cast<pointer>(from.operator->());
				Vector_iterator<T> tmp(ptr);
				this->m_base = tmp;
			}
			Vector_const_reverse_iterator(const Vector_reverse_iterator<T>& from)
			{
				this->m_base = from.operator->();
			}

			Vector_const_reverse_iterator& operator=(const Vector_const_reverse_iterator& it)
			{
				if (this != &it) 
					this->m_base = it.m_base;
				return (*this);
			}
			const_reference operator*() const
			{
				return (*(Vector_iterator<T>(this->m_base)));
			}
			const_pointer operator->() const { return (&this->operator*()); }
	};
}

#endif /* ********************************************** VECTOR_ITERATORS_HPP */