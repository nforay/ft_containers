/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/04 19:14:37 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <limits>
# include "utils.hpp"

# include <iostream>

namespace ft
{
	/**
	 * 
	*/
	template <class Key, class T, class Compare = std::less<Key>
	, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		struct Node
		{
			ft::pair<const Key, T>	val;
			Node*					parent;
			Node*					left;
			Node*					right;
		};

		public:

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename Alloc::template
			rebind<Node>::other									Node_allocator;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef List_iterator<T, Node>						iterator;
			typedef List_const_iterator<T, Node>				const_iterator;
			typedef List_const_reverse_iterator<T, Node>		const_reverse_iterator;
			typedef List_reverse_iterator<T, Node>				reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:

			Node*			_root;
			size_type		_size;
			key_compare		_comp;
			allocator_type	_alloc;

		public:

			/**
			 * @brief empty container constructor (default constructor):
			 * Constructs an empty container, with no elements.
			 * @tparam comp Binary predicate that, taking two element keys as
			 * argument, returns true if the first argument goes before the
			 * second argument in the strict weak ordering it defines, and false
			 * otherwise. This shall be a function pointer or a function object.
			 * @tparam alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				
			}

			/**
			 * @brief range constructor: Constructs a container with as many
			 * elements as the range [first,last), with each element constructed
			 * from its corresponding element in that range.
			 * @tparam first,last Input iterators to the initial and final
			 * positions in a range. The range used is [first,last), which
			 * includes all the elements between first and last, including the
			 * element pointed by first but not the element pointed by last.
			 * @tparam comp Binary predicate that, taking two element keys as
			 * argument, returns true if the first argument goes before the
			 * second argument in the strict weak ordering it defines, and false
			 * otherwise. This shall be a function pointer or a function object.
			 * @tparam alloc Allocator object. The container keeps and uses an
			 * internal copy of this allocator.
			*/
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				while (first != last)
					this->insert(*first++);
			}

			/**
			 * @brief Copy constructor: Constructs a container with a copy of
			 * each of the elements in x.
			 * @tparam x Another map object of the same type (with the same
			 * class template arguments Key, T, Compare and Alloc), whose
			 * contents are either copied or acquired.
			*/
			map(const map& x)
			: _root(NULL), _size(0), _comp(x.comp), _alloc(x.alloc)
			{
				for (const_iterator it = x.begin(); it != x.end(); it++)
					this->insert(*it);
			}

			/**
			 * @brief Map destructor: Destroys the container object.
			 * This destroys all container elements, and deallocates all the
			 * storage capacity allocated by the map container using its
			 * allocator.
			*/
			~map()
			{
				this->clear();
			}

			/**
			 * @brief Copies all the elements from x into the container,
			 * changing its size accordingly.
			 * @return *this
			*/
			map& operator=(const map& x)
			{
				map tmp(x);
				this->swap(tmp);
				return (*this);
			}

/*
** --------------------------------- ITERATORS ---------------------------------
*/

			/**
			 * @brief Returns an iterator referring to the first element in the
			 * map container.
			 * @return An iterator to the first element in the container.
			*/
			iterator begin()
			{
				return (iterator(this->tree_smallest(_root)));
			}

			/**
			 * @brief Returns a const iterator referring to the first element in
			 * the map container.
			 * @return A const iterator to the first element in the container.
			*/
			const_iterator begin() const
			{
				return (const_iterator(this->tree_smallest(_root)));
			}

			/**
			 * @brief Returns an iterator referring to the past-the-end element
			 * in the map container.
			 * @return An iterator to the past-the-end element in the container.
			*/
			iterator end()
			{
				return (iterator(this->tree_biggest(_root)->right));
			}

			/**
			 * @brief Returns a const iterator referring to the past-the-end
			 * element in the map container.
			 * @return A const iterator to the past-the-end element in the
			 * container.
			*/
			const_iterator end() const
			{
				return (const_iterator(this->tree_biggest(_root)->right));
			}

			/**
			 * @brief Returns a reverse iterator pointing to the last element in
			 * the container (i.e., its reverse beginning).
			 * @return A reverse iterator to the reverse beginning of the
			 * sequence container.
			*/
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a const reverse iterator pointing to the last
			 * element in the container (i.e., its reverse beginning).
			 * @return A const reverse iterator to the reverse beginning of the
			 * sequence container.
			*/
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * @brief Returns a reverse iterator pointing to the theoretical
			 * element right before the first element in the map container
			 * (which is considered its reverse end).
			 * @return A reverse iterator to the reverse end of the sequence
			 * container.
			*/
			reverse_iterator rend()
			{
				return (reverse_iterator(this->tree_smallest(_root)->left));
			}

			/**
			 * @brief Returns a const reverse iterator pointing to the
			 * theoretical element right before the first element in the map
			 * container (which is considered its reverse end).
			 * @return A const reverse iterator to the reverse end of the
			 * sequence container.
			*/
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->tree_smallest(_root)->left));
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			 * @brief Returns whether the map container is empty (i.e. whether
			 * its size is 0).
			 * @return true if the container size is 0, false otherwise.
			*/
			bool empty() const
			{
				return (_size == 0);
			}

			/**
			 * @brief Returns the number of elements in the map container.
			 * @return The number of elements in the container.
			*/
			size_type size() const
			{
				return (_size);
			}

			/**
			 * @brief Returns the maximum number of elements that the map
			 * container can hold.
			 * @return The maximum number of elements a map container can hold
			 * as content.
			*/
			size_type max_size() const
			{
				return (Node_allocator(_alloc).max_size());
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			 * @brief If k matches the key of an element in the container, the
			 * function returns a reference to its mapped value. If k does not
			 * match the key of any element in the container, the function
			 * inserts a new element with that key and returns a reference to
			 * its mapped value.
			*/
			mapped_type& operator[](const key_type& k)
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (found->val.second);
				found = Node_allocator(_alloc).allocate(1);
				found->right = NULL;
				found->left = NULL;
				_alloc.construct(&found->val,
					make_pair(k, mapped_type()));
				_root = this->tree_insert(_root, NULL, &found);
				return (found->val.second);
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by one.
			 * @param val Value to be copied to (or moved as) the inserted
			 * element.
			*/
			pair<iterator,bool> insert(const value_type& val)
			{
				Node* found = this->tree_search(_root, val.first);

				if (found)
					return (ft::pair<iterator, bool>(iterator(found), false));
				found = Node_allocator(_alloc).allocate(1);
				found->right = NULL;
				found->left = NULL;
				_alloc.construct(&found->val, val);
				_root = this->tree_insert(_root, NULL, &found);
				return (ft::pair<iterator, bool>(iterator(found), true));
			}

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by one.
			 * @param position Hint for the position where the element can be
			 * inserted. Notice that this is just a hint and does not force the
			 * new element to be inserted at that position within the map
			 * container.
			 * @param val Value to be copied to (or moved as) the inserted
			 * element.
			*/
			iterator insert(iterator position, const value_type& val)
			{
				
			}

			/**
			 * @brief Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of
			 * elements inserted.
			 * @param first,last Iterators specifying a range of elements.
			 * Copies of the elements in the range [first,last) are inserted in
			 * the container.
			*/
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				
			}

			/**
			 * @brief Removes a single element from the map container.
			 * This effectively reduces the container size by one and destroy
			 * the element.
			 * @param position Iterator pointing to a single element to be
			 * removed from the map.
			*/
			void erase(iterator position)
			{
				
			}

			/**
			 * @brief Removes a single element from the map container.
			 * This effectively reduces the container size by one and destroy
			 * the element.
			 * @param k Key of the element to be removed from the map.
			*/
			size_type erase(const key_type& k)
			{
				size_type tmp = this->size();
				_root = this->tree_delete(_root, k);
				return ((this->size() == tmp) ? 0 : 1);
			}

			/**
			 * @brief Removes from the map container a range of elements
			 * ([first,last)). This effectively reduces the container size by
			 * the number of elements removed, which are destroyed.
			 * @param first,last Iterators specifying a range within the map
			 * container to be removed: [first,last). i.e., the range includes
			 * all the elements between first and last, including the element
			 * pointed by first but not the one pointed by last.
			*/
			void erase(iterator first, iterator last)
			{

			}

			/**
			 * @brief Exchanges the content of the container by the content of
			 * x, which is another map of the same type. Sizes may differ.
			 * @param x  Another map container of the same type as this (i.e.,
			 * with the same template parameters, Key, T, Compare and Alloc)
			 * whose content is swapped with that of this container.
			*/
			void swap(map& x)
			{
				swap(_root, x._root);
				swap(_size, x._size);
				swap(_comp, x._comp);
				swap(_alloc, x._alloc);
			}

			/**
			 * @brief Removes all elements from the map container (which are
			 * destroyed), leaving the container with a size of 0.
			*/
			void clear()
			{
				this->erase(this->begin(), this->end());
			}

/*
** -------------------------------- OBSERVERS ----------------------------------
*/

			/**
			 * @brief Returns a copy of the comparison object used by the
			 * container to compare keys.
			 * @return The comparison object.
			*/
			key_compare key_comp() const
			{
				return (_comp);
			}

			class value_compare
			{
				// in C++98, it is required to inherit binary_function<value_type,value_type,bool>
				friend class map;

				public:

					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

				bool operator()(const value_type &x, const value_type &y) const
				{
					return Compare(x.first, y.first);
				}

				protected:

					key_compare		comp;

					value_compare(Compare c) : comp(c) {}
			};

			/**
			 * @brief Returns a comparison object that can be used to compare
			 * two elements to get whether the key of the first one goes before
			 * the second.
			 * @return The comparison object for element values.
			*/
			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}

/*
** -------------------------------- OPERATIONS ---------------------------------
*/

			/**
			 * @brief Searches the container for an element with a key
			 * equivalent to k and returns an iterator to it if found,
			 * otherwise it returns an iterator to map::end.
			 * @param k Key to search for.
			 * @return An iterator to the element, if an element with specified
			 * key is found, or map::end otherwise.
			*/
			iterator find(const key_type& k)
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (iterator(found));
				return (this->end());
			}

			/**
			 * @brief Searches the container for an element with a key
			 * equivalent to k and returns a const iterator to it if found,
			 * otherwise it returns a const iterator to map::end.
			 * @param k Key to search for.
			 * @return A const iterator to the element, if an element with
			 * specified key is found, or map::end otherwise.
			*/
			const_iterator find(const key_type& k) const
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (const_iterator(found));
				return (this->end());
			}

			/**
			 * @brief Searches the container for elements with a key equivalent
			 * to k and returns the number of matches.
			 * @param k Key to search for.
			 * @return 1 if the container contains an element whose key is
			 * equivalent to k, or zero otherwise.
			*/
			size_type count(const key_type& k) const
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (1);
				return (0);
			}

			/**
			 * @brief Returns an iterator pointing to the first element in the
			 * container whose key is not considered to go before k (i.e.,
			 * either it is equivalent or goes after).
			 * @param k Key to search for.
			 * @return An iterator to the the first element in the container
			 * whose key is not considered to go before k, or map::end if all
			 * keys are considered to go before k.
			*/
			iterator lower_bound(const key_type& k)
			{
				
			}

			/**
			 * @brief Returns a const iterator pointing to the first element in
			 * the container whose key is not considered to go before k (i.e.,
			 * either it is equivalent or goes after).
			 * @param k Key to search for.
			 * @return A const iterator to the the first element in the
			 * container whose key is not considered to go before k, or map::end
			 * if all keys are considered to go before k.
			*/
			const_iterator lower_bound(const key_type& k) const
			{
				
			}

			/**
			 * @brief Returns an iterator pointing to the first element in the
			 * container whose key is considered to go after k.
			 * @param k Key to search for.
			 * @return An iterator to the the first element in the container
			 * whose key is considered to go after k, or map::end if no keys are
			 * considered to go after k.
			*/
			iterator upper_bound(const key_type& k)
			{
				
			}

			/**
			 * Returns a const iterator pointing to the first element in the
			 * container whose key is considered to go after k.
			 * @param k Key to search for.
			 * @return A const iterator to the the first element in the
			 * container whose key is considered to go after k, or map::end if
			 * no keys are considered to go after k.
			*/
			const_iterator upper_bound(const key_type& k) const
			{
				
			}

			/**
			 * @brief Returns the bounds of a range that includes all the
			 * elements in the container which have a key equivalent to k.
			 * Because the elements in a map container have unique keys, the
			 * range returned will contain a single element at most.
			 * @param k Key to search for.
			 * @return The function returns a pair, whose member pair::first is
			 * the lower bound of the range (the same as lower_bound),
			 * and pair::second is the upper bound (the same as upper_bound).
			*/
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				
			}

			/**
			 * @brief Returns the bounds of a range that includes all the
			 * elements in the container which have a key equivalent to k.
			 * Because the elements in a map container have unique keys, the
			 * range returned will contain a single element at most.
			 * @param k Key to search for.
			 * @return The function returns a pair, whose member pair::first is
			 * the lower bound of the range (the same as lower_bound),
			 * and pair::second is the upper bound (the same as upper_bound).
			*/
			pair<iterator,iterator> equal_range(const key_type& k)
			{
				
			}

/*
** -------------------------------- ALLOCATOR ----------------------------------
*/

			/**
			 * @brief Returns a copy of the allocator object associated with the
			 * map.
			 * @return The allocator.
			*/
			allocator_type get_allocator() const
			{
				return (_alloc);
			}

/*
** ---------------------------- PRIVATE FUNCTIONS ------------------------------
*/

			void print(void)//TEMP
			{
				std::cout << "root: " << _root->val.first << "=" << _root->val.second << std::endl;
				inorder(_root, NULL);
				std::cout << std::endl;
			}
			void inorder(Node *node, Node *parent) //TEMP DEBUG PRINT
			{
				if (node == NULL)
					return;
				inorder(node->left, node);
				std::cout << node->val.first << "=" << node->val.second << " ";
				inorder(node->right, node);
			}

		private:

			template<class U>
			void swap(U& u1, U& u2)
			{
				U tmp = u2;
				u2 = u1;
				u1 = tmp;
			}

			/**
			 * @brief Calculate the height of the given AVL Tree
			 * @param node Pointer to the starting node for the depth calculation
			 * @return An int representing the height of the given node
			*/
			int		tree_height(Node* node) const
			{
				int	height = 0;
				if (node != NULL)
					height = std::max(tree_height(node->left),
						tree_height(node->right)) + 1;
				return (height);
			}

			/**
			 * @brief Calculate the balance factor of the given node
			 * @param node Pointer to the node to be balanced
			 * @return An int representing te balance factor. The value –1
			 * indicates that the left sub-tree contains one extra, the value +1
			 * indicates that the left sub-tree contains one extra and value 0
			 * shows that the tree includes equal nodes on each side.
			*/
			int		tree_getbalance(Node* node) const
			{
				if (node == NULL)
					return (0);
				return (tree_height(node->left) - tree_height(node->right));
			}

			/**
			 * @brief Performs a Right-Right rotation of the given node.
			 * This rotation is performed when a new node is inserted at the
			 * right child of the right subtree.
			*/
			Node*	tree_rr_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->right;
				new_parent->parent = node->parent;
				node->parent = new_parent;
				node->right = new_parent->left;
				if (new_parent->left)
					new_parent->left->parent = node;
				new_parent->left = node;
				return (new_parent);
			}

			/**
			 * 
			*/
			Node*	tree_ll_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->left;
				new_parent->parent = node->parent;
				node->parent = new_parent;
				node->left = new_parent->right;
				if (new_parent->right)
					new_parent->right->parent = node;
				new_parent->right = node;
				return (new_parent);
			}

			/**
			 * 
			*/
			Node*	tree_lr_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->left;
				node->left = this->tree_rr_rotate(new_parent);
				return (this->tree_ll_rotate(node));
			}

			/**
			 * 
			*/
			Node*	tree_rl_rotate(Node* node)
			{
				Node*	new_parent;

				new_parent = node->right;
				node->right = this->tree_ll_rotate(new_parent);
				return (this->tree_rr_rotate(node));
			}

			/**
			 * 
			*/
			Node*	tree_balance(Node* node)
			{
				int	factor = tree_getbalance(node);

				if (factor > 1)
				{
					if (tree_getbalance(node->left) > 0)
						return (this->tree_ll_rotate(node));
					else
						return (this->tree_lr_rotate(node));
				}
				else if (factor < -1)
				{
					if (tree_getbalance(node->right) < 0)						
						return (this->tree_rr_rotate(node));
					else
						return (this->tree_rl_rotate(node));
				}
				return (node);
			}

			/**
			 * 
			*/
			Node*	tree_insert(Node* node, Node* parent, Node** new_node)
			{
				if (node == NULL)
				{
					(*new_node)->parent = parent;
					if (!_root)
						_root = *new_node;
					return (node = *new_node);
				}
				else if ((*new_node)->val.first == node->val.first)
					return (NULL);
				else if ((*new_node)->val.first < node->val.first)
				{
					node->left = tree_insert(node->left, node, new_node);
					return (this->tree_balance(node));
				}
				else if ((*new_node)->val.first > node->val.first)
				{
					node->right = tree_insert(node->right, node, new_node);
					return (this->tree_balance(node));
				}
				return (node);
			}

			/**
			 * 
			*/
			Node*	tree_delete(Node* node, key_type key)
			{
				if (node == NULL)
					return (NULL);
				if (node->val.first > key)
					node->left = tree_delete(node->left, key);
				else if (node->val.first < key)
					node->right = tree_delete(node->right, key);
				Node*	tmp;
				if ((node->right == NULL) || (node->left == NULL))
				{
					tmp = node->right ? node->right : node->left;
					if (tmp == NULL)
					{
						tmp = node;
						node = NULL;
					}
					else
					{
						tmp->parent = node->parent;
						*node = *tmp;
					}
					_alloc.destroy(&tmp->val);
					Node_allocator(_alloc).deallocate(tmp, 1);
					_size--;
				}
				else
				{
					tmp = this->tree_smallest(node->right);
					_alloc.destroy(&node->val);
					_alloc.construct(&node->val, tmp->val);
					node->right = tree_delete(node->right, tmp->val);
				}
				if (node == NULL)
					return (node);
				int	factor = tree_getbalance(node);
				if (factor > 1)
				{
					if (tree_getbalance(node->left) >= 0)
						return (tree_ll_rotate(node));
					else
						return (this->tree_rl_rotate(node));
				}
				else if (factor < -1)
				{
					if (tree_getbalance(node->right) <= 0)
						return (tree_rr_rotate(node));
					else
						return (this->tree_lr_rotate(node));
				}
				return (node);
			}

			/**
			 * 
			*/
			Node*	tree_search(Node* node, key_type key)
			{
				if (node == NULL)
					return (NULL);
				if (!_comp(node->val.first, key) && !_comp(key, node->val.first))
					return (node);
				if (node->val.first > key)
					return (tree_search(node->left, key));
				else if (node->val.first < key)
					return (tree_search(node->right, key));
				return (NULL);
			}

			/**
			 * 
			*/
			Node*	tree_smallest(Node* node)
			{
				while (node->left != NULL)
					node = node->left;
				return (node);
			}

			/**
			 * 
			*/
			Node*	tree_biggest(Node* node)
			{
				while (node->right != NULL)
					node = node->right;
				return (node);
			}
	};
}

#endif /* *********************************************************** MAP_HPP */