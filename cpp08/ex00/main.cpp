/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:22:11 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/08 21:05:05 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int>	v;
	std::list<int>		l;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	
	std::cout << easyfind(v, 3) << std::endl;
	try {std::cout << easyfind(v, 4) << std::endl;}
	catch (std::exception &e) {std::cout << "Not found" << std::endl;}
	std::cout << easyfind(l, 2) << std::endl;
}
