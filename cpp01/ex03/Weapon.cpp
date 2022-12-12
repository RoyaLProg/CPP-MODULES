/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:05:22 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:05:52 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::~Weapon( void )
{
}

std::string const &Weapon::getType( void )
{
	return (this->_type);
}

void Weapon::setType( std::string type )
{
	this->_type = type;
}
