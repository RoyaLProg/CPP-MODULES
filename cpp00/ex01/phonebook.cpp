/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:02 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/26 15:00:10 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>
#include "structures.hpp"

void	print_main(void)
{
	std::cout << "**********PHONEBOOK**********" << std::endl;
	std::cout << "*  BETTER THAN EVER BEFORE  *" << std::endl;
	std::cout << "*****************************" << std::endl;
	std::cout << "PLS ENTER ONE OF THE FOLLWING :" << std::endl;
	std::cout << "ADD, SEARCH, EXIT" << std::endl;
}

void	add_contact(PhoneBook *phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	phonebook->add_contact(first_name, last_name, nickname, number, darkest_secret);
}

bool	process_input(std::string input, PhoneBook *Phonebook)
{
	std::transform(input.begin(), input.end(), input.begin(),  ::toupper);
	if (!input.compare("SEARCH"))
		return false;
	if (!input.compare("ADD"))
		add_contact(Phonebook);
	if (!input.compare("EXIT"))
		return true;
	return (false);
}

int	main(void)
{
	std::string input;
	PhoneBook	Phonebook;
	while (1)
	{
		print_main();
		std::cin >> input;
		if (process_input(input, &Phonebook))
			break ;		
	}
	return (EXIT_SUCCESS);
}
