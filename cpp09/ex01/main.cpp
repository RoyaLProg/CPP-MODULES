/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:32:52 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 07:24:06 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage : ./RPN \"operations\"" << std::endl;
		return (0);
	}
	RPN::load(av[1]);
	try { RPN::resolve(); }
    catch (std::exception & e) { std::cout << e.what();}
}

