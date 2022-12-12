/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:42:20 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 10:49:30 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::Zombie( void )
{
	this->_name = "unnamed_zombie";
}


Zombie::~Zombie( void )
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::setName( std::string name )
{
	this->_name = name;
}

void Zombie::announce( void )
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
