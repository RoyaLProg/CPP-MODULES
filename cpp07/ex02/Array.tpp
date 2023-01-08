/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:16:48 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/08 16:35:38 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array(void) : _array(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array const & src)
{
	*this = src;
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw std::exception();
	return this->_array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs)
{
	if (this != &rhs)
	{
		delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = rhs._array[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return this->_size;
}
