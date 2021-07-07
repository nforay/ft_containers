/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 03:14:41 by nforay            #+#    #+#             */
/*   Updated: 2021/07/07 03:35:56 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "list.hpp"

namespace ft
{
	/**
	 * @brief Queues are a type of container adaptor, specifically designed to
	 * operate in a FIFO context (first-in first-out), where elements are
	 * inserted into one end of the container and extracted from the other.
	 * Queues are implemented as containers adaptors, which are classes that use
	 * an encapsulated object of a specific container class as its underlying
	 * container, providing a specific set of member functions to access its
	 * elements. Elements are pushed into the "back" of the specific container
	 * and popped from its "front".
	 * @tparam T Type of the elements.
	 * @tparam Container Type of the internal underlying container object where
	 * the elements are stored.
	*/
	template <class T, class Container = list<T> >
	class queue
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:

			container_type		_ctnr;

		public:

			/**
			 * Constructs a queue container adaptor object. A container adaptor
			 * keeps internally a container object as data. This container
			 * object is a copy of the ctnr argument passed to the constructor,
			 * if any, otherwise it is an empty container.
			 * @param ctnr Container object. 
			*/
			explicit queue(const container_type& ctnr = container_type())
			: _ctnr(ctnr) {}

			/**
			 * @brief Copy constructor: Constructs a container with a copy of
			 * each of the elements in x.
			 * @param x Another queue object of the same type (with the same
			 * class template arguments T and Container), whose
			 * contents are either copied or acquired.
			*/
			queue(const queue& x) : _ctnr(x._ctnr) {}

			~queue() {}

			/**
			 * @brief Copies all the elements from x into the container,
			 * changing its size accordingly.
			 * @return *this
			*/
			queue& operator=(const queue& x)
			{
				queue tmp(x);
				swap(_ctnr, tmp._ctnr);
				return *this;
			}

			/**
			 * @brief Returns whether the queue is empty: i.e. whether its size
			 * is zero.
			 * @return true if the underlying container's size is 0, false
			 * otherwise.
			*/
			bool empty() const
			{
				return (_ctnr.empty());
			}

			/**
			 * @brief Returns the number of elements in the queue.
			 * @return The number of elements in the underlying container.
			*/
			size_type size() const
			{
				return (_ctnr.size());
			}

			/**
			 * @brief Returns a reference to the next element in the queue.
			 * The next element is the "oldest" element in the queue and the
			 * same element that is popped out from the queue when queue::pop
			 * is called.
			 * @return A reference to the next element in the queue.
			*/
			value_type& front()
			{
				return (_ctnr.front());
			}

			/**
			 * @brief Returns a const reference to the next element in the
			 * queue. The next element is the "oldest" element in the queue and
			 * the same element that is popped out from the queue when
			 * queue::pop is called.
			 * @return A const reference to the next element in the queue.
			*/
			const value_type& front() const
			{
				return (_ctnr.front());
			}

			/**
			 * @brief Returns a reference to the last element in the queue. This
			 * is the "newest" element in the queue (i.e. the last element
			 * pushed into the queue).
			 * @return A reference to the last element in the queue.
			*/
			value_type& back()
			{
				return (_ctnr.back());
			}

			/**
			 * @brief Returns a const reference to the last element in the
			 * queue. This is the "newest" element in the queue (i.e. the last
			 * element pushed into the queue).
			 * @return A const reference to the last element in the queue.
			*/
			const value_type& back() const
			{
				return (_ctnr.back());
			}

			/**
			 * @brief Inserts a new element at the end of the queue, after its
			 * current last element. The content of this new element is
			 * initialized to val.
			 * @param val Value to which the inserted element is initialized.
			*/
			void push(const value_type& val)
			{
				_ctnr.push_back(val);
			}

			/**
			 * @brief Removes the next element in the queue, effectively
			 * reducing its size by one. The element removed is the "oldest"
			 * element in the queue whose value can be retrieved by calling
			 * member queue::front.
			*/
			void pop()
			{
				_ctnr.pop_front();
			}

			friend bool operator==(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{
				return (lhs._ctnr == rhs._ctnr);
			}

			friend bool operator<(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
			{
				return (lhs._ctnr < rhs._ctnr);
			}
	};

	template <class T, class Container>
	bool operator!=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator<=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator>(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>=(const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif /* ********************************************************* QUEUE_HPP */