/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 06:47:42 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/17 07:09:50 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./merge [numbers]" << std::endl;
		return (0);
	}
	PMergeMe::load(av + 1);
	PMergeMe::execute();
	return (0);
}
