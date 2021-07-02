/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:43 by nforay            #+#    #+#             */
/*   Updated: 2021/07/01 17:47:41 by nforay           ###   ########.fr       */
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
			size_t					height;
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
	};
}

#endif /* *********************************************************** MAP_HPP */