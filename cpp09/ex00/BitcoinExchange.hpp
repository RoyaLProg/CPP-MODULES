/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:29:12 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 04:50:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <iostream>

class	BitcoinExchange{
	public:
		static	std::map<std::string, double>	load();
		// static	void	unload();
		static	void	read_input(char *);
	
	private:
		BitcoinExchange();
		static bool								verification(std::string);
		static void								print_line(std::string);
		static std::map<std::string, double>	_data;
};
