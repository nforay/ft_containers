/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/04 03:02:24 by nforay           ###   ########.fr       */
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
			 * @brief Constructs an empty container, with no elements.
			*/
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				
			}

			/**
			 * @brief Constructs a container with as many elements as the range
			 * [first,last), with each element constructed from its
			 * corresponding element in that range.
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
			 * @brief Constructs a container with a copy of each of the elements
			 * in x.
			*/
			map(const map& x)
			: _root(NULL), _size(0), _comp(x.comp), _alloc(x.alloc)
			{
				for (const_iterator it = x.begin(); it != x.end(); it++)
					this->insert(*it);
			}

			/**
			 * 
			*/
			~map()
			{
				this->clear();
			}

			/**
			 * 
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
			 * 
			*/
			iterator begin()
			{
				return (iterator(this->tree_smallest(_root)));
			}

			/**
			 * 
			*/
			const_iterator begin() const
			{
				return (const_iterator(this->tree_smallest(_root)));
			}

			/**
			 * 
			*/
			iterator end()
			{
				return (iterator(this->tree_biggest(_root)->right));
			}

			/**
			 * 
			*/
			const_iterator end() const
			{
				return (const_iterator(this->tree_biggest(_root)->right));
			}

			/**
			 * 
			*/
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * 
			*/
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->tree_biggest(_root)));
			}

			/**
			 * 
			*/
			reverse_iterator rend()
			{
				return (reverse_iterator(this->tree_smallest(_root)->left));
			}

			/**
			 * 
			*/
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->tree_smallest(_root)->left));
			}

/*
** --------------------------------- CAPACITY ----------------------------------
*/

			/**
			 * 
			*/
			bool empty() const
			{
				return (_size == 0);
			}

			/**
			 * 
			*/
			size_type size() const
			{
				return (_size);
			}

			/**
			 * 
			*/
			size_type max_size() const
			{
				return (Node_allocator(_alloc).max_size());
			}

/*
** ------------------------------ ELEMENT ACCESS -------------------------------
*/

			/**
			 * 
			*/
			mapped_type& operator[](const key_type& k)
			{
				Node* found = this->tree_search(_root, k);

				if (found)
					return (found->val.second);
				found = Node_allocator(_alloc).allocate(1);
				_alloc.construct(&found->val,
					make_pair<key_type, mapped_type>(k, mapped_type()));
				//
				_root = this->tree_insert(_root, NULL, &found);
				std::cout << "Inserted: " << found->val.first << " val " << found->val.second << std::endl;
				return (found->val.second);
				//return (this->tree_insert(_root, NULL, found)->val.second);
			}

/*
** -------------------------------- MODIFIERS ----------------------------------
*/

			/**
			 * 
			*/
			pair<iterator,bool> insert(const value_type& val)
			{
				Node* found = this->tree_search(_root, val.first);

				if (found)
					return (ft::pair<iterator, bool>(iterator(found), false));
				found = Node_allocator(_alloc).allocate(1);
				_alloc.construct(&found->val, val);
				_root = this->tree_insert(_root, NULL, &found);
				std::cout << "Inserted: " << found->val.first << " val " << found->val.second << std::endl;
				return (ft::pair<iterator, bool>(iterator(found), true));
			}

			/**
			 * 
			*/
			iterator insert(iterator position, const value_type& val)
			{
				
			}

			/**
			 * 
			*/
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				
			}

			/**
			 * 
			*/
			void erase(iterator position)
			{
				
			}

			/**
			 * 
			*/
			size_type erase(const key_type& k)
			{
				
			}

			/**
			 * 
			*/
			void erase(iterator first, iterator last)
			{

			}

			/**
			 * 
			*/
			void swap(map& x)
			{
				
			}

			/**
			 * 
			*/
			void clear()
			{
				
			}

/*
** -------------------------------- OBSERVERS ----------------------------------
*/

			/**
			 * 
			*/
			key_compare key_comp() const
			{
				return (_comp);
			}

			struct value_compare
			{
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
			 * 
			*/
			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}

/*
** -------------------------------- OPERATIONS ---------------------------------
*/

			/**
			 * 
			*/
			iterator find(const key_type& k)
			{
				
			}

			/**
			 * 
			*/
			const_iterator find(const key_type& k) const
			{
				
			}

			/**
			 * 
			*/
			size_type count(const key_type& k) const
			{
				
			}

			/**
			 * 
			*/
			iterator lower_bound(const key_type& k)
			{
				
			}

			/**
			 * 
			*/
			const_iterator lower_bound(const key_type& k) const
			{
				
			}

			/**
			 * 
			*/
			iterator upper_bound(const key_type& k)
			{
				
			}

			/**
			 * 
			*/
			const_iterator upper_bound(const key_type& k) const
			{
				
			}

			/**
			 * 
			*/
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const
			{
				
			}

			/**
			 * 
			*/
			pair<iterator,iterator> equal_range(const key_type& k)
			{
				
			}

/*
** -------------------------------- ALLOCATOR ----------------------------------
*/

			/**
			 * 
			*/
			allocator_type get_allocator() const
			{
				
			}

/*
** ---------------------------- PRIVATE FUNCTIONS ------------------------------
*/

			void print(void) { inorder(_root); }
			void inorder(Node *node) //TEMP
			{
				if (node == NULL)
					return;
				inorder(node->left);
				std::cout << node->val.first << "=" << node->val.second << " ";
				inorder(node->right);
			}

		private:

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