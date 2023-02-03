/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:17 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/03 07:35:38 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = "ScavTrap";
}

ScavTrap::~ScavTrap( void ) 
{ 
	std::cout << "ScavTrap destructor called" << std::endl;
	return ; 
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

void	ScavTrap::guardGate( void )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	std::cout << "ScavTrap " << this->_name 
	<< " has entered in Gate keeper mode" << std::endl;
	this->_energyPoints--;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}
