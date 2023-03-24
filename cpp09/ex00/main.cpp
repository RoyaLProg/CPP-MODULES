/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:37:04 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 04:48:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av){
	if (ac != 2)
	{
		std::cout << "usage : ./btc [/path/to/inpute_file]" << std::endl;
		return 0;
	}
    try{ BitcoinExchange::read_input(av[1]); }
    catch ( std::invalid_argument const& e) { std::cout << e.what(); return (1);}

	return (0);
}

