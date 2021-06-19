/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:33:56 by nforay            #+#    #+#             */
/*   Updated: 2021/06/19 18:44:20 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>

namespace ft
{
	/**
	 * @brief Lists are sequence containers that allow constant time insert and
	 * erase operations anywhere within the sequence, and iteration in both
	 * directions.
	 * @tparam T Type of the elements.
	 * @tparam Alloc Type of the allocator object used to define the storage
	 * allocation model. By default, the allocator class template is used, which
	 * defines the simplest memory allocation model and is value-independent. 
    */
	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef List_iterator<T>							iterator;
			typedef List_const_iterator<T>						const_iterator;
			typedef List_const_reverse_iterator<T>				const_reverse_iterator;
			typedef List_reverse_iterator<T>					reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:

			struct Node
			{
				T			val;
				Node*		next;
				Node*		prev;
			};
			Node*			_head;
			size_type		_size;
			allocator_type	_alloc;

		public:

			/**
			 * @brief empty container constructor (default constructor):
			 * Constructs an empty container, with no elements.
			 * @param alloc Allocator object.
			 * The container keeps and uses an internal copy of this allocator.
			*/
			explicit list(const allocator_type& alloc = allocator_type())
			: _size(0), _alloc(alloc)
			{
				
			}

			/**
			 * @brief fill constructor: Constructs a container with n elements.
			 * Each element is a copy of val.
			 * @param n Initial container size (i.e., the number of elements
			 * in the container at construction).
			 * @param val Value to fill the container with. Each of the n 
			 * elements in the container is initialized to a copy of this value.
			 * @param alloc Allocator object.
			 * The container keeps and uses an internal copy of this allocator.
			*/
			explicit list(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
			: _size(n), _alloc(alloc)
			{
				
			}

			/**
			 * @brief range constructor: Constructs a container with as many
			 * elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range, in the same order. 
			 * The range includes all the elements between first and last, 
			 * including the element pointed by first but not the element 
			 * pointed by last.
			 * @param first Input iterator to the initial position in a range.
			 * @param last Input iterator to the final position in a range.
			 * @param alloc Allocator object.
			 * The container keeps and uses an internal copy of this allocator.
			*/
			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			{
				
			}

			/**
			 * @brief copy constructor: Constructs a container with a copy of
			 * each of the elements in x, in the same order.
			 * @param x Another list object of the same type (with the same 
			 * class template arguments), whose contents are either copied or
			 * acquired.
			*/
			list(const list& x)
			{
				
			}

			/**
			 * @brief List destructor: Destroys the container object. This 
			 * destroys all container elements, and deallocates all the storage 
			 * capacity allocated by the list container using its allocator.
			*/
			~list()
			{
				
			}

			/**
			 * @brief  Assigns new contents to the container, replacing its
			 * current contents, and modifying its size accordingly. The 
			 * container preserves its current allocator, which is used to 
			 * allocate additional storage if needed.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			*/
			list& operator=(const list& x)
			{
				
			}
	};
}

#endif /* ********************************************************** LIST_HPP */