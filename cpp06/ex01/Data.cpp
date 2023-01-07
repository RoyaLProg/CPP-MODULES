/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:00:30 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/06 11:25:53 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_someValue = "default";
}

Data::~Data()
{
}

Data::Data(std::string const & value)
{
	_someValue = value;
}

Data::Data(Data const & src)
{
	*this = src;
}

Data & Data::operator=(Data const & rhs)
{
	if (this != &rhs)
	{
		_someValue = rhs._someValue;
	}
	return *this;
}

bool Data::operator==(Data const & rhs) const
{
	return _someValue == rhs._someValue;
}

std::string & Data::getSomeValue(void)
{
	return _someValue;
}
