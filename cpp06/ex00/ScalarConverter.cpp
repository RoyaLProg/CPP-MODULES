/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:55:21 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/22 19:07:38 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	ScalarConverter::c_to_other(std::string str)
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

void	ScalarConverter::i_to_other(std::string str)
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

void	ScalarConverter::f_to_other(std::string str)
{
	float f;

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

void	ScalarConverter::d_to_other(std::string str)
{
	double d;

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

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		c_to_other(str);
	else if (str.find('f') != std::string::npos && str.compare("+inf") != 0 && str.compare("-inf") != 0)
		f_to_other(str);
	else if (str.find('.') != std::string::npos || str.compare("nan") == 0
			|| str.compare("+inf") == 0 || str.compare("-inf") == 0)
		d_to_other(str);
	else
		i_to_other(str);
}

ScalarConverter::~ScalarConverter()
{
}
