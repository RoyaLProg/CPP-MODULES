/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:08:26 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:14:54 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA( void )
{
}

void HumanA::attack( void )
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
