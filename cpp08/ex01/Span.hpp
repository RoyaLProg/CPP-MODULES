/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:42:55 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/10 04:46:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & rhs);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
};

#endif
