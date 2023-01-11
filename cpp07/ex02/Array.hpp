/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:16:04 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/11 12:35:44 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include "Array.tpp"

template <typename T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const & src);
		~Array<T>(void);

		Array<T> & operator=(Array<T> const & rhs);

		T & operator[](unsigned int i);

		unsigned int size(void) const;

	private:
		T *_array;
		unsigned int _size;
};

#endif
