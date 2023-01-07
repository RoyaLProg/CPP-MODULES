/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:55:40 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/06 10:52:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	c_to_other(std::string str)
{
	char c = str[0];

	std::cout << "char: ";
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: ";
	try
	{
		std::cout << static_cast<int>(c) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(c) << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(c) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void	i_to_other(std::string str)
{
	int i = std::stoi(str);

	std::cout << "char: ";
	try
	{
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;		
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	
	std::cout << "int: ";
	std::cout << i << std::endl;
	std::cout << "float: ";
	try
	{
		std::cout << static_cast<float>(i) << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(i) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void	f_to_other(std::string str)
{
	float f;

	std::cout << "here f_to_other" << std::endl;
	if (str.compare("nanf") == 0)
		f = std::numeric_limits<float>::quiet_NaN();
	else if (str.compare("+inff") == 0)
		f = std::numeric_limits<float>::infinity();
	else if (str.compare("-inff") == 0)
		f = -std::numeric_limits<float>::infinity();
	else
		f = std::stof(str);
	std::cout << "char: ";
	try
	{
		if (!str.compare("nanf") || !str.compare("+inff") || !str.compare("-inff"))
			std::cout << "impossible" << std::endl;
		else if (f < 32 || f > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		if (!str.compare("nanf") || !str.compare("+inff") || !str.compare("-inff"))
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(f) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	std::cout << f << "f" << std::endl;
	std::cout << "double: ";
	try
	{
		std::cout << static_cast<double>(f) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void	d_to_other(std::string str)
{
	double d;

	std::cout << "here" << std::endl;
	if (str.compare("nan") == 0)
		d = std::numeric_limits<double>::quiet_NaN();
	else if (str.compare("+inf") == 0)
		d = std::numeric_limits<double>::infinity();
	else if (str.compare("-inf") == 0)
		d = -std::numeric_limits<double>::infinity();
	else
		d = std::stod(str);

	std::cout << "char: ";
	try 
	{
		if (!str.compare("nan") || !str.compare("+inf") || !str.compare("-inf"))
			std::cout << "impossible" << std::endl;
		else if (d < 32 || d > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		if (!str.compare("nan") || !str.compare("+inf") || !str.compare("-inf"))
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(d) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		float f = static_cast<float>(d);
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
	std::cout << "double: ";
	std::cout << d << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (1);
	}
	std::string	arg = std::string(av[1]);
	if (arg.length() == 1 && !ft_isdigit(arg[0]))
		c_to_other(arg);
	else if ((arg.find('f') != std::string::npos && arg.compare("-inf") != 0 && arg.compare("+inf") != 0)
			|| !arg.compare("-inff") || !arg.compare("+inff") || !arg.compare("nanf"))
		f_to_other(arg);
	else if (arg.find('.') != std::string::npos || !arg.compare("-inf") || !arg.compare("+inf") || !arg.compare("nan"))
		d_to_other(arg);
	else
		i_to_other(arg);
	return (0);
}
