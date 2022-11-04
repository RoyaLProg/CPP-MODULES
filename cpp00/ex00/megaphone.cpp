/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:09 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/27 09:59:21 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	toUpper(std::string s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = toupper(s[i]);
	return (s);
}
void	megaphone(std::string argv[])
{
	for (size_t i = 1; !argv[i].empty(); i++)
	{
		argv[i] = toUpper(argv[i]);
		std::cout << argv[i];		
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::string s[argc + 1];

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 0; i < argc; i++)
		s[i].assign(argv[i]);
	s[argc] = "";
	megaphone(s);
}
