/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:02 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/25 18:54:43 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>

void	print_main(void)
{
	std::cout << "**********PHONEBOOK**********" << std::endl;
	std::cout << "* BETTER THAN NEVER BEFORE !*" << std::endl;
	std::cout << "*****************************" << std::endl;
	std::cout << "PLS ENTER ONE OF THE FOLLWING :" << std::endl;
	std::cout << "ADD, SEARCH, EXIT" << std::endl;
}

bool	process_input(std::string input)
{
	std::transform(input.begin(), input.end(), input.begin(),  ::toupper);
	if (!input.compare("SEARCH"))
		return false;
	if (!input.compare("ADD"))
		return false;
	if (!input.compare("EXIT"))
		return true;
	return (false);
}

int	main(void)
{
	std::string input;
	while (1)
	{
		print_main();
		std::cin >> input;
		if (process_input(input))
			break ;		
	}
	return (EXIT_SUCCESS);
}
