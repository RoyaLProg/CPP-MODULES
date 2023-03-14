/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:45:28 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/07 20:24:10 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <stdexcept>

Span::Span( unsigned int n ):_n( n ) { }

void Span::addNumber( int n )
{
	if ( _v.size() < _n )
		_v.push_back( n );
	else
		throw std::length_error( "Span is full" );
}

size_t	Span::shortestSpan()
{
	if ( _v.size() < 2 )
		throw std::length_error("Span is too small");
	std::sort( _v.begin(), _v.end() );
	int min = _v[1] - _v[0];
	for ( size_t i = 1; i < _v.size() - 1; i++ )
	{
		if ( _v[i + 1] - _v[i] < min )
			min = _v[i + 1] - _v[i];
	}
	return min;
}

size_t	Span::longestSpan()
{
	if ( _v.size() < 2 )
		throw std::length_error("Span is too small");
	std::sort( _v.begin(), _v.end() );
	return _v[_v.size() - 1] - _v[0];
}

Span::Span( Span const & src )
{
	*this = src;
}

Span::~Span(void) { }

Span &Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	if ( _v.size() + std::distance( it, ite ) > _n )
		throw std::length_error( "Span is full" );
	_v.insert( _v.end(), it, ite );
}
