/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:13:48 by ccambium          #+#    #+#             */
/*   Updated: 2022/11/04 10:33:27 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

		Contact::Contact(std::string first_name, std::string last_name,
				std::string nickname, std::string number, 
				std::string darkest_secret)
		{
			this->first_name = first_name;
			this->last_name = last_name;
			this->nickname = nickname;
			this->number = number;
			this->darkest_secret = darkest_secret;
		}
		Contact::Contact(void)
		{
			this->first_name = "";
			this->last_name = "";
			this->nickname = "";
			this->number = "";
			this->darkest_secret = "";
		}
		std::string Contact::getFirstName(void) { return this->first_name; }
		std::string Contact::getLastName(void) { return this->last_name; }
		std::string Contact::getNickname(void) { return this->nickname; }
		std::string Contact::getNumber(void) { return this->number; }
		std::string Contact::getDarkestSecret(void) { return this->darkest_secret; }
