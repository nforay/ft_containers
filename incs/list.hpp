/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:33:56 by nforay            #+#    #+#             */
/*   Updated: 2021/06/20 03:09:09 by nforay           ###   ########.fr       */
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
			: _size(0), _alloc(alloc), _head(NULL)
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
			: _size(0), _alloc(alloc), _head(NULL)
			{
				
			}

			/**
			 * @brief range constructor: Constructs a container with as many
			 * elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range, in the same order. 
			 * The range includes all the elements between first and last, 
			 * including the element pointed by first but not the element 
			 * pointed by last.
			 * @param first,last Input iterators to the initial and final
			 * positions in a range.
			 * @param alloc Allocator object.
			 * The container keeps and uses an internal copy of this allocator.
			*/
			template <class InputIterator>
			list(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			: _size(0), _alloc(alloc), _head(NULL)
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
			: _size(0), _alloc(x._alloc), _head(NULL)
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

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			/**
			 * @brief Returns an iterator pointing to the first element in the 
			 * list container.
			 * @return An iterator to the beginning of the sequence container.
			 * If the container is empty, the returned iterator value shall not 
			 * be dereferenced.
			*/
			iterator begin()
			{
				
			}

			/**
			 * @brief Returns a const_iterator pointing to the first element in 
			 * the list container.
			 * @return A const_iterator to the beginning of the sequence 
			 * container.
			 * If the container is empty, the returned iterator value shall not 
			 * be dereferenced.
			*/
			const_iterator begin() const
			{
				
			}

			/**
			 * @brief Returns an iterator referring to the past-the-end element 
			 * in the list container.
			 * @return An iterator to the element past the end of the sequence. 
			 * If the container is empty, this function returns the same as 
			 * list::begin.
			*/
			iterator end()
			{
				
			}

			/**
			 * @brief Returns a const_iterator referring to the past-the-end 
			 * element in the list container.
			 * @return A const_iterator to the element past the end of the 
			 * sequence. If the container is empty, this function returns the 
			 * same as list::begin.
			*/
			const_iterator end() const
			{
				
			}

			/**
			 * @brief Returns a reverse iterator pointing to the last element in
			 * the container (i.e., its reverse beginning). Reverse iterators 
			 * iterate backwards: increasing them moves them towards the 
			 * beginning of the container. rbegin points to the element right 
			 * before the one that would be pointed to by member end.
			 * @return A reverse_iterator to the reverse beginning of the
			 * sequence container.
			*/
			reverse_iterator rbegin()
			{
				
			}

			/**
			 * @brief Returns a reverse iterator pointing to the last element in
			 * the container (i.e., its reverse beginning). Reverse iterators 
			 * iterate backwards: increasing them moves them towards the 
			 * beginning of the container. rbegin points to the element right 
			 * before the one that would be pointed to by member end.
			 * @return A const_reverse_iterator to the reverse beginning of the
			 * sequence container.
			*/
			const_reverse_iterator rbegin() const
			{
				
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			 * @brief Returns whether the list container is empty (i.e. whether
			 * its size is 0).
			 * @return true if the container size is 0, false otherwise.
			*/
			bool empty() const
			{
				
			}

			/**
			 * @brief Returns the number of elements in the list container.
			 * @return The number of elements in the container.
			*/
			size_type size() const
			{
				
			}

			/**
			 * @brief Returns the maximum number of elements that the list
			 * container can hold.
			 * @return The maximum number of elements the object can hold as
			 * content.
			*/
			size_type max_size() const
			{
				
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			 * @brief Returns a reference to the first element in the list
			 * container. Unlike member list::begin, which returns an iterator
			 * to this same element, this function returns a direct reference.
			 * @return A reference to the first element in the list container.
			*/
			reference front()
			{
				
			}

			/**
			 * @brief Returns a const reference to the first element in the list
			 * container. Unlike member list::begin, which returns an iterator
			 * to this same element, this function returns a direct reference.
			 * @return A const reference to the first element in the list
			 * container.
			*/
			const_reference front() const
			{
				
			}

			/**
			 * @brief Returns a reference to the last element in the list
			 * container. Unlike member list::end, which returns an iterator
			 * just past this element, this function returns a direct reference.
			 * @return A reference to the last element in the list.
			*/
			reference back()
			{
				
			}

			/**
			 * @brief Returns a const reference to the last element in the list
			 * container. Unlike member list::end, which returns an iterator
			 * just past this element, this function returns a direct reference.
			 * @return A const reference to the last element in the list.
			*/
			const_reference back() const
			{
				
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			 * @brief Assigns new contents to the list container, replacing its
			 * current contents, and modifying its size accordingly. the new
			 * contents are elements constructed from each of the elements in
			 * the range between first and last, in the same order, including
			 * the element pointed by first but not the element pointed by last.
			 * @param first,last Iterators to the initial and final
			 * positions in a sequence.
			*/
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				
			}

			/**
			 * @brief Assigns new contents to the list container, replacing its
			 * current contents, and modifying its size accordingly. The new
			 * contents are n elements, each initialized to a copy of val.
			 * @param n New size for the container.
			 * @param val Value to fill the container with. Each of the n
			 * elements in the container will be initialized to a copy of this
			 * value.
			*/
			void assign(size_type n, const value_type& val)
			{
				
			}

			/**
			 * @brief Inserts a new element at the beginning of the list, right
			 * before its current first element. The content of val is copied
			 * (or moved) to the inserted element.
			 * @param val Value to be copied (or moved) to the inserted element.
			*/
			void push_front(const value_type& val)
			{
				
			}

			/**
			 * @brief Removes the first element in the list container,
			 * effectively reducing its size by one. This destroys the removed
			 * element.
			*/
			void pop_front()
			{
				
			}

			/**
			 * @brief Adds a new element at the end of the list container,
			 * after its current last element. The content of val is copied
			 * (or moved) to the new element. This effectively increases the
			 * container size by one.
			 * @param val Value to be copied (or moved) to the new element.
			*/
			void push_back(const value_type& val)
			{
				
			}

			/**
			 * @brief Removes the last element in the list container,
			 * effectively reducing the container size by one. This destroys the
			 * removed element.
			*/
			void pop_back()
			{
				
			}

			/**
			 * @brief The container is extended by inserting new elements before
			 * the element at the specified position. This effectively increases
			 * the list size by the amount of elements inserted.
			 * @param position Position in the container where the new elements
			 * are inserted.
			 * @param val Value to be copied or moved to the inserted elements.
			*/
			iterator insert(iterator position, const value_type& val)
			{
				
			}

			/**
			 * @brief The container is extended by inserting new elements before
			 * the element at the specified position. This effectively increases
			 * the list size by the amount of elements inserted.
			 * @param position Position in the container where the new elements
			 * are inserted.
			 * @param n Number of elements to insert. Each element is
			 * initialized to a copy of val.
			 * @param val Value to be copied or moved to the inserted elements.
			*/
			void insert(iterator position, size_type n, const value_type& val)
			{
				
			}

			/**
			 * @brief The container is extended by inserting new elements before
			 * the element at the specified position. This effectively increases
			 * the list size by the amount of elements inserted. Notice that the
			 * range includes all the elements between first and last, including
			 * the element pointed by first but not the one pointed by last.
			 * @param position Position in the container where the new elements
			 * are inserted.
			 * @param first,last Iterators to the initial and final
			 * positions in a range.
			*/
			template <class InputIterator>
			void insert(iterator position, InputIterator first,
				InputIterator last)
			{
				
			}

			/**
			 * @brief Removes from the list container a single element at
			 * position. This effectively reduces the container size by the
			 * number of elements removed, which are destroyed.
			 * @param position Iterator pointing to a single element to be
			 * removed from the list.
			 * @return An iterator pointing to the element that followed the
			 * last element erased by the function call. This is the container
			 * end if the operation erased the last element in the sequence.
			*/
			iterator erase(iterator position)
			{
				
			}

			/**
			 * @brief Removes from the list container a range of elements
			 * ([first,last)). This effectively reduces the container size by
			 * the number of elements removed, which are destroyed. The range
			 * includes all the elements between first and last, including the
			 * element pointed by first but not the one pointed by last.
			 * @param first,last Iterators to the initial and final
			 * positions in a range.
			 * @return An iterator pointing to the element that followed the
			 * last element erased by the function call. This is the container
			 * end if the operation erased the last element in the sequence.
			*/
			iterator erase(iterator first, iterator last)
			{
				
			}

			/**
			 * @brief Exchanges the content of the container by the content of x
			 * which is another list of the same type. Sizes may differ. After
			 * the call to this member function, the elements in this container
			 * are those which were in x before the call, and the elements of x
			 * are those which were in this. All iterators, references and
			 * pointers remain valid for the swapped objects.
			 * @param x Another list container of the same type as this
			 * (i.e., with the same template parameters, T and Alloc) whose
			 * content is swapped with that of this container.
			*/
			void swap(list& x)
			{
				
			}

			/**
			 * @brief Resizes the container so that it contains n elements.
			 * If n is smaller than the current container size, the content is
			 * reduced to its first n elements, removing those beyond
			 * (and destroying them).
			 * If n is greater than the current container size, the content is
			 * expanded by inserting at the end as many elements as needed to
			 * reach a size of n. If val is specified, the new elements are
			 * initialized as copies of val, otherwise, they are
			 * value-initialized.
			 * @param n New container size, expressed in number of elements.
			 * @param val Object whose content is copied to the added elements
			 * in case that n is greater than the current container size.
			*/
			void resize(size_type n, value_type val = value_type())
			{
				
			}

			/**
			 * @brief Removes all elements from the list container (which are
			 * destroyed), and leaving the container with a size of 0.
			*/
			void clear()
			{
				
			}

/*
** -------------------------------- OPERATIONS ---------------------------------
*/

			/**
			 * @brief Transfers elements from x into the container, inserting
			 * them at position. This effectively inserts those elements into
			 * the container and removes them from x, altering the sizes of both
			 * containers. The operation does not involve the construction or
			 * destruction of any element. They are transferred, no matter
			 * whether x is an lvalue or an rvalue, or whether the value_type
			 * supports move-construction or not.
			 * @param position Position within the container where the elements
			 * of x are inserted.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			*/
			void splice(iterator position, list& x)
			{
				
			}

			/**
			 * @brief Transfers elements from x into the container, inserting
			 * them at position. This effectively inserts those elements into
			 * the container and removes them from x, altering the sizes of both
			 * containers. The operation does not involve the construction or
			 * destruction of any element. They are transferred, no matter
			 * whether x is an lvalue or an rvalue, or whether the value_type
			 * supports move-construction or not.
			 * @param position Position within the container where the elements
			 * of x are inserted.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			 * @param i Iterator to an element in x. Only this single element is
			 * transferred.
			*/
			void splice(iterator position, list& x, iterator i)
			{
				
			}

			/**
			 * @brief Transfers elements from x into the container, inserting
			 * them at position. This effectively inserts those elements into
			 * the container and removes them from x, altering the sizes of both
			 * containers. The operation does not involve the construction or
			 * destruction of any element. They are transferred, no matter
			 * whether x is an lvalue or an rvalue, or whether the value_type
			 * supports move-construction or not.
			 * @param position Position within the container where the elements
			 * of x are inserted.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			 * @param first,last Iterators to the initial and final
			 * positions in a range.
			*/
			void splice(iterator position, list& x, iterator first,
				iterator last)
			{
				
			}

			/**
			 * @brief Removes from the container all the elements that compare
			 * equal to val. This calls the destructor of these objects and
			 * reduces the container size by the number of elements removed.
			 * @param val Value of the elements to be removed.
			*/
			void remove(const value_type& val)
			{
				
			}

			/**
			 * @brief Removes from the container all the elements for which
			 * Predicate pred returns true. This calls the destructor of these
			 * objects and reduces the container size by the number of elements
			 * removed.
			 * @param pred Unary predicate that, taking a value of the same type
			 * as those contained in the forward_list object, returns true for
			 * those values to be removed from the container, and false for
			 * those remaining.
			*/
			template <class Predicate>
			void remove_if(Predicate pred)
			{
				
			}

			/**
			 * @brief Removes all but the first element from every consecutive
			 * group of equal elements in the container. Notice that an element
			 * is only removed from the list container if it compares equal to
			 * the element immediately preceding it. Thus, this function is
			 * especially useful for sorted lists.
			*/
			void unique()
			{
				
			}

			/**
			 * @brief Takes as argument a specific comparison function that
			 * determine the "uniqueness" of an element. In fact, any behavior
			 * can be implemented (and not only an equality comparison), but
			 * notice that the function will call binary_pred(*i,*(i-1)) for
			 * all pairs of elements (where i is an iterator to an element,
			 * starting from the second) and remove i from the list if the
			 * predicate returns true.
			 * @param binary_pred Binary predicate that, taking two values of
			 * the same type than those contained in the list, returns true to
			 * remove the element passed as first argument from the container,
			 * and false otherwise. This shall be a function pointer or a
			 * function object.
			*/
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				
			}

			/**
			 * @brief Merges x into the list by transferring all of its elements
			 * at their respective ordered positions into the container
			 * (both containers shall already be ordered).
			 * This effectively removes all the elements in x (which becomes
			 * empty), and inserts them into their ordered position within
			 * container (which expands in size by the number of elements
			 * transferred). The operation is performed without constructing nor
			 * destroying any element: they are transferred, no matter whether x
			 * is an lvalue or an rvalue, or whether the value_type supports
			 * move-construction or not.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			*/
			void merge(list& x)
			{
				
			}

			/**
			 * @brief Merges x into the list by transferring all of its elements
			 * at their respective ordered positions into the container
			 * (both containers shall already be ordered).
			 * This effectively removes all the elements in x (which becomes
			 * empty), and inserts them into their ordered position within
			 * container (which expands in size by the number of elements
			 * transferred). The operation is performed without constructing nor
			 * destroying any element: they are transferred, no matter whether x
			 * is an lvalue or an rvalue, or whether the value_type supports
			 * move-construction or not.
			 * @param x A list object of the same type (i.e., with the same
			 * template parameters, T and Alloc).
			 * @param comp Binary predicate that, taking two values of the same
			 * type than those contained in the list, returns true if the first
			 * argument is considered to go before the second in the strict weak
			 * ordering it defines, and false otherwise. This shall be a
			 * function pointer or a function object.
			*/
			template <class Compare>
			void merge(list& x, Compare comp)
			{
				
			}

			/**
			 * @brief Sorts the elements in the list, altering their position
			 * within the container. The sorting is performed by applying an
			 * algorithm that uses operator< to compare elements.
			*/
			void sort()
			{
				
			}

			/**
			 * @brief Sorts the elements in the list, altering their position
			 * within the container. The sorting is performed by applying comp
			 * to compare elements.
			 * @param comp Binary predicate that, taking two values of the same
			 * type of those contained in the list, returns true if the first
			 * argument goes before the second argument in the strict weak
			 * ordering it defines, and false otherwise. This shall be a
			 * function pointer or a function object.
			*/
			template <class Compare>
			void sort (Compare comp)
			{
				
			}

			/**
			 * @brief Reverses the order of the elements in the list container.
			*/
			void reverse()
			{
				
			}

/*
** -------------------------------- OBSERVERS ----------------------------------
*/

			/**
			 * @brief Returns a copy of the allocator object associated with the
			 * list container.
			 * @return The allocator.
			*/
			allocator_type get_allocator() const
			{
				
			}

/*
** -------------------------------- OVERLOADS ----------------------------------
*/

			template <class T, class Alloc>
			bool operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			template <class T, class Alloc>
			bool operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			//note: only 1 friend needed
			template <class T, class Alloc>
			bool operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			template <class T, class Alloc>
			bool operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			template <class T, class Alloc>
			bool operator>(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			template <class T, class Alloc>
			bool operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				
			}

			/**
			 * @brief The contents of container x are exchanged with those of y.
			 * Both container objects must be of the same type (same template
			 * parameters), although sizes may differ.
			 * @param x,y list containers of the same type (i.e., having both
			 * the same template parameters, T and Alloc).
			*/
			template <class T, class Alloc>
			void swap(list<T,Alloc>& x, list<T,Alloc>& y)
			{
				
			}
	};
}

#endif /* ********************************************************** LIST_HPP */