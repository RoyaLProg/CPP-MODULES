/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:02 by ccambium          #+#    #+#             */
/*   Updated: 2022/11/05 11:52:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>
#include "PhoneBook.hpp"

std::string toUpper(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    	s[i] = toupper(s[i]);
    return (s);
}

std::string	resize(std::string content)
{
	if (content.length() > 10)
	{
		content.erase(content.begin() + 9, content.end());
		content.append(".");
	}
	return (content);
}

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

	std::cout << std::endl << std::endl << std::endl << std::endl;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter number: ";
	std::getline(std::cin, number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	phonebook->add_contact(first_name, last_name, nickname, number, darkest_secret);
}

bool	process_input(std::string input, PhoneBook *Phonebook)
{
	input = toUpper(input);
	if (!input.compare("SEARCH"))
		Phonebook->search();
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
		std::getline(std::cin, input);
		if (process_input(input, &Phonebook))
			break ;		
		std::cout << std::endl << std::endl;
	}
	return (EXIT_SUCCESS);
}
