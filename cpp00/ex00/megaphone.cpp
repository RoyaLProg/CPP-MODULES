/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:08:09 by ccambium          #+#    #+#             */
/*   Updated: 2022/10/25 18:22:57 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<bits/stdc++.h>

void	megaphone(std::string argv[])
{
	for (size_t i = 1; !argv[i].empty(); i++)
	{
		std::transform(argv[i].begin(), argv[i].end(), argv[i].begin(), ::toupper);
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
