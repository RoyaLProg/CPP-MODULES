/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:35:08 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 05:41:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <exception>

std::map<std::string, double>	BitcoinExchange::_data = BitcoinExchange::load();

void BitcoinExchange::read_input(char * file)
{
		std::ifstream	ifs;
		std::string		line;

		ifs.open(file);
		if (ifs.fail())
		{
			std::cout << "ERROR : could not open " << file << std::endl;
			return ;
		}
		std::getline(ifs, line);
		while (!line.empty())
		{
			if (verification(line))
				print_line(line);
			getline(ifs, line);
		}
}

std::map<std::string, double>	BitcoinExchange::load()
{
	std::ifstream	ifs;
	std::string		line;
	std::map<std::string, double> data = std::map<std::string, double>();

	ifs.open("data.csv");
	if (ifs.fail())
		throw std::invalid_argument("ERROR : could not open data.csv, make sure the file exist and has proper read rights !");
	std::getline(ifs, line);
	while (!line.empty())
	{
		data.insert(
			std::make_pair(
				line.substr(0, line.find(',')),
				std::atof(line.substr(line.find(',') + 1, line.size()).c_str())
			)
		);
		std::getline(ifs, line);
	}
	return data;
}

bool isNumber(const std::string& s)
{
	bool			flag = false;
	long unsigned	i;
	s[0] == '-' ? i = 1 : i = 0;
    for (; i < s.size(); i++) {
        if (std::isdigit(s[i]) == 0) 
		{
			if (s[i] == '.' && flag == false)
			{
				flag = true;
				continue ;
			}
            return false;
		}
    }
    return true;
}

bool	checkFormat(std::string line)
{
	size_t	x = line.find('|');
	if (x == std::string::npos
	|| x == 0
	|| x == line.size()
	|| line[x - 1] != ' '
	|| line[x + 1] != ' '
	|| line.find('|', x + 1) != std::string::npos)
	{
		std::cout << "ERROR : \"" << line << "\" invalid format" << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::verification(std::string line)
{
	std::string	s;
	
	s = line.substr(line.find('|') + 2, line.size() - 1);
	if (checkFormat(line) == false)
		return (false);
	if (!isNumber(s))
	{
		std::cout << "ERROR : \"" << line << "\" invalid value" << std::endl; 
		return (false);
	}
	if (s.size() > 4)
	{
		std::cout << "ERROR : \"" << line << "\" value too high" << std::endl; 
		return (false);
	}
	return (true);
}

void	BitcoinExchange::print_line(std::string line)
{
	double	value;
	double	mult;
	std::map<std::string, double>::iterator it;

	try {mult = BitcoinExchange::_data.at(line.substr(0, line.find('|') - 1));}
	catch (std::exception &e) {std::cout << "ERROR : " << line.substr(0, line.find('|') - 1) << " not found in data" << std::endl; return ;}
	value = std::atof(
		line.substr(line.find('|') + 2, 
		line.size()).c_str()
	);

	if (value > 1000)
	{
		std::cout << "ERROR : " << line << " value too high" << std::endl;
		return ;
	}
	if (value < 0)
	{
		std::cout << "ERROR : " << line << " value not positive" << std::endl;
		return ;
	}
	std::cout << line.substr(0, line.find('|') - 1) << " => " << value << " = " << value * mult << std::endl;
}
