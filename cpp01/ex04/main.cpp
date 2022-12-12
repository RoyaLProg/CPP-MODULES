/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 07:56:45 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/02 08:26:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLosers.hpp"

void	demo(void)
{
	// if file doesn't exist :
	std::cout << "if file doesn't exist :" << std::endl;
	sed("random file go", "s1", "s2");

	// if file exists :
	std::cout << "if file exists :" << std::endl;
	sed("main.cpp", "main", "vroum");

	// if s1 is empty :
	std::cout << "if s1 is empty :" << std::endl;
	sed("main.cpp", "", "vroum");

	// if s2 is empty :
	std::cout << "if s2 is empty :" << std::endl;
	sed("main.cpp.replace", "vroum", "");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		demo();
	else if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	else
		sed(argv[1], argv[2], argv[3]);
	return (0);
}
