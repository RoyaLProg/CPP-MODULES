/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:36:47 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/26 14:54:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact{

	public:
		Contact(std::string first_name, std::string last_name,
				std::string nickname, std::string number, 
				std::string darkest_secret)
		{
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->number = number;
			this->darkest_secret = darkest_secret;
		}
		Contact(void)
		{
			this->first_name = "";
			this->last_name = "";
			this->nickname = "";
			this->number = "";
			this->darkest_secret = "";
		}
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string darkest_secret;
};

class PhoneBook{
	private:
		Contact contacts[8];
		int		contact_count;
	public:
		PhoneBook()
		{
			this->contact_count = 0;
		}
		void	add_contact(std::string first_name, std::string last_name,
							std::string nickname, std::string number,
							std::string darkest_secret)
		{
			this->contacts[this->contact_count] = *new Contact(first_name, last_name,
																nickname, number,
																darkest_secret);
			this->contact_count++;
			if (this->contact_count == 8)
				this->contact_count = 0;
				
		}
		void	print_contacts(void)
		{
			for (int i = 0; i < this->contact_count; i++)
			{
				std::cout << "First name: " << this->contacts[i].first_name << std::endl;
				std::cout << "Last name: " << this->contacts[i].last_name << std::endl;
				std::cout << "Nickname: " << this->contacts[i].nickname << std::endl;
				std::cout << "Number: " << this->contacts[i].number << std::endl;
				std::cout << "Darkest secret: " << this->contacts[i].darkest_secret << std::endl;
			}
		}
		
		
} Phonebook;
