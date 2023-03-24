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
#include <ctime>

std::map<std::string, double>	BitcoinExchange::_data;

void BitcoinExchange::read_input(char * file)
{
		std::ifstream	ifs;
		std::string		line;

		
        try { _data = BitcoinExchange::load(); }
        catch ( std::exception &e ) {throw ;}
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
        throw std::invalid_argument("ERROR : could not open data.csv, make sure the file exist and has proper read rights !\n");
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

static bool isNumber(const std::string& s)
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

static bool	checkFormat(std::string line)
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

static bool check_date(std::string date)
{
    struct tm tm;
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
    {
        std::cout << "ERROR : invalid date or date format : " << date << "\n";
        return (false);
    }
    return (true);
}

bool	BitcoinExchange::verification(std::string line)
{
	std::string	s;
	
    s = line.substr(0, line.find('|') - 1);
    if (!check_date(s))
        return (false);
    if (!checkFormat(line))
	    return (false);
	s = line.substr(line.find('|') + 2, line.size() - 1);
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

static void make_new_time(struct tm *tm)
{
    if (tm->tm_mday > 1)
        tm->tm_mday -= 1;
    else
    {
        if (tm->tm_mon > 0)
            tm->tm_mon -= 1;
        else
        {
            if (tm->tm_year > 0)
                tm->tm_year -= 1;
            else
                throw std::invalid_argument("Some you have input an invalid date !");
            tm->tm_mon = 11;
        }
        tm->tm_mday = 31;
    }
}

static double   find_closest_date(std::string date, std::map<std::string, double> data)
{
    struct tm tm;
    char    s[11];
    double  mult;

    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
        return (0);
    while (1)
    {
        make_new_time(&tm);
        strftime(s, 11, "%Y-%m-%d", &tm);
        try {mult = data.at(std::string(s)); break;}
        catch (std::exception & e) {continue ;}
    }
    return (mult);
}

void	BitcoinExchange::print_line(std::string line)
{
	double	value;
	double	mult;
	std::map<std::string, double>::iterator it;

	try {mult = BitcoinExchange::_data.at(line.substr(0, line.find('|') - 1));}
	catch (std::exception & e) {mult = find_closest_date(line.substr(0, line.find('|') - 1), BitcoinExchange::_data);}
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
