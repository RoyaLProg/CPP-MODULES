/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:51 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/05 10:10:33 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main( void )
{
	Harl		harl;
	std::string	level;

	std::cout << "Enter a complaint level: ";
	std::cin >> level;
	harl.complain(level);
	return (0);
}
