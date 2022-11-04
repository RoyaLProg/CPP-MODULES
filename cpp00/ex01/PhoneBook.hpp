/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:36:47 by ccambium          #+#    #+#             */
/*   Updated: 2022/11/04 14:02:06 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_HPP
# define PhoneBook_HPP
# include <iostream>

class Contact{

	public:
		Contact(std::string first_name, std::string last_name,
				std::string nickname, std::string number, 
				std::string darkest_secret);
		Contact(void);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getNumber(void);
		std::string getDarkestSecret(void);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string darkest_secret;
};

class PhoneBook{

	public:
		PhoneBook(void);
		void	add_contact(std::string first_name, std::string last_name,
							std::string nickname, std::string number,
							std::string darkest_secret);
		void	print_contact(int i);
		void	search(void);
	private:
		Contact	contacts[8];
		int		contact_count;
		
};

std::string	resize(std::string content);
#endif
