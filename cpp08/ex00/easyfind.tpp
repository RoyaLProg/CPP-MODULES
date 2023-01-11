/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:17:27 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/10 04:25:18 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	easyfind(T &container, int n)
{
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();
	size_t i = 0;

	while (it != ite)
	{
		if (*it == n)
			return (i);
		it++;
		i++;
	}
	throw std::exception();
}
