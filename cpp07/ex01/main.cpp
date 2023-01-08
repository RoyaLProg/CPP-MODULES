/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:20:32 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/07 17:25:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	print(int const &i)
{
	std::cout << i << std::endl;
}

void	print(std::string const &i)
{
	std::cout << i << std::endl;
}

int	main(void)
{
	int		tab[5] = {1, 2, 3, 4, 5};
	std::string	tab2[5] = {"1", "2", "3", "4", "5"};

	iter(tab, 5, &print);
	iter(tab2, 5, &print);
	return (0);
}
