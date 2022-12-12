/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:27:29 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/02 08:24:39 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLosers.hpp"

static std::string	replace(std::string::size_type pos, std::string line,
	std::string s1, std::string s2)
{
	std::string	tmp[2];

	tmp[0] = line.substr(0, pos);
	tmp[1] = line.substr(pos + s1.length(), line.length());
	line = tmp[0] + s2 + tmp[1];
	return (line);
}

void	sed(const std::string filename, std::string s1, std::string s2)
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string line;
	std::string::size_type pos;

	if (s1.empty())
	{
		std::cout << "Error: s1 is empty" << std::endl;
		return ;
	}
	ifs.open(filename.c_str());
	if (ifs.fail())
	{
		std::cout << "Error: file not found" << std::endl;
		return ;
	}
	ofs.open((filename + ".replace").c_str());
	while (std::getline(ifs, line))
	{
		pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = replace(pos, line, s1, s2);
			pos += s2.length();
		}
		ofs << line << std::endl;
	}
}
