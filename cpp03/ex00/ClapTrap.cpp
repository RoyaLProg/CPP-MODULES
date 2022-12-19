/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:00:39 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/08 16:56:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	this->_name = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

ClapTrap::~ClapTrap( void ) { return ; }

ClapTrap::ClapTrap( std::string name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

void	ClapTrap::attack( std::string const & target )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	std::cout << "ClapTrap " << this->_name
	<< " attacks " << target 
	<< ", causing " << this->_attackDamage << " points of damage!" 
	<< std::endl;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name 
	<< " has been repaired for " << amount << " points!" 
	<< std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name 
	<< " has taken " << amount << " points of damage!" 
	<< std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

