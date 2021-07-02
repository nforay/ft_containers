/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/02 19:47:48 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <limits>
# include "utils.hpp"

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
			key_compare		_comp;
			allocator_type	_alloc;
			size_type		_size;

		public:

			

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
			}

			/**
			 * 
			*/
			Node*	tree_insert(Node* node, Node* parent, Node* new_node)
			{
				if (node == NULL)
				{
					new_node->parent = parent;
					return (node = new_node);
				}
				else if (new_node->val.first == node->val.first)
					return (NULL);
				else if (new_node->val.first < node->val.first)
				{
					node->left = tree_insert(node->left, node, new_node);
					return (this->tree_balance(node));
				}
				else if (new_node->val.first > node->val.first)
				{
					node->right = tree_insert(node->right, node, new_node);
					return (this->tree_balance(node));
				}
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
						tmp->parent = found->parent;
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