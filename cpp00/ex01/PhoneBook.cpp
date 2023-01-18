/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:02:40 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/18 13:59:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
}
void	PhoneBook::add_contact(std::string first_name, std::string last_name,
					std::string nickname, std::string number,
					std::string darkest_secret)
{
	this->contacts[this->contact_count % 8] = *new Contact(first_name, last_name,
														nickname, number,
														darkest_secret);
	this->contact_count++;
	if (this->contact_count == 8)
		this->contact_count = 0;
		
}

void	PhoneBook::print_contact(int i)
{
	std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Number: " << this->contacts[i].getNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::search(void)
{
	int			pick;
	std::string	x;
	
	std::cout << std::endl << std::endl << std::endl << std::endl;
	if (this->contact_count == 0)
	{
		std::cout << "NO CONTACT YET ... KEEP BEING ALONE NERD !" << std::endl;
		return ;
	}
	for (int i = 0; i < this->contact_count; i++)
	{
		if (i == 8)
			break ;
		std::cout << std::setw(10) << i << '|';
		std::cout << std::setw(10) << resize(this->contacts[i].getFirstName()) << '|';
		std::cout << std::setw(10) << resize(this->contacts[i].getLastName()) << '|';
		std::cout << std::setw(10) << resize(this->contacts[i].getNickname()) << '|' << std::endl;
	}
	std::cout << "pick a contact you wish to see :";
	std::getline(std::cin, x);
	pick = atoi(x.c_str());
	if (pick >= this->contact_count && pick >= 0)
	{
		std::cout << "INDEX NUMBER GREATER THAN NUMBER OF CONTACTS" << std::endl;
		return ;
	}
	if (pick < 0)
	{
		std::cout << "NICE TRY" << std::endl;
		return ;
	}
	std::cout << std::endl << std::endl << std::endl << std::endl;
	this->print_contact(pick);
}
