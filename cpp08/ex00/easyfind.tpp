/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:17:27 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/08 21:04:42 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template <typename T>
int	easyfind(T &container, int n)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	typename T::iterator itr;
	itr = std::find(it, ite, n);
	if (itr == ite)
		throw std::exception();
	return (std::distance(it, itr));
}
