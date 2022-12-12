/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:54:55 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:13:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string	&stringREF = s; 

	std::cout << "s memory adress: " << &s << std::endl;
	std::cout << "stringPTR memory adress held: " << stringPTR << std::endl;
	std::cout << "stringREF memory adress held: " << &stringREF << std::endl;
	
	std::cout << "s value: " << s << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;
	
	return (0);
}
