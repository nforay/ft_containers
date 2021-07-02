/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/02 15:10:30 by nforay           ###   ########.fr       */
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
				
			}

			/**
			 * @brief Calculate the balance factor of the given node
			 * @param node Pointer to the node to be balanced
			 * @return An int representing te balance factor. The value –1
			 * indicates that the left sub-tree contains one extra, the value +1
			 * indicates that the left sub-tree contains one extra and value 0
			 * shows that the tree includes equal nodes on each side.
			*/
			int		tree_balance(Node* node) const
			{
				
			}

			/**
			 * @brief Performs a Right-Right rotation of the given node. This
			 * rotation is performed when a new node is inserted at the right
			 * child of the right subtree.
			*/
			Node*	tree_rr_rotate(Node* node)
			{
				
			}

			/**
			 * 
			*/
			Node*	tree_ll_rotate(Node* node)
			{
				
			}

			/**
			 * 
			*/
			Node*	tree_lr_rotate(Node* node)
			{
				
			}

			/**
			 * 
			*/
			Node*	tree_lr_rotate(Node* node)
			{
				
			}

			/**
			 * 
			*/
			Node*	tree_insert(Node* node)
			{
				
			}

			/**
			 * 
			*/
			Node*	tree_delete(Node* node)
			{
				
			}
	};
}

#endif /* *********************************************************** MAP_HPP */