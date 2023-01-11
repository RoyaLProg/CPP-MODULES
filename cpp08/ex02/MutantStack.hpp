/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:34:12 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/11 07:46:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const & src) : std::stack<T>(src) {}
		virtual ~MutantStack() {}

		MutantStack & operator=(MutantStack const & rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return (std::stack<T>::c.begin()); }

		iterator end() { return (std::stack<T>::c.end()); }
};

#endif
