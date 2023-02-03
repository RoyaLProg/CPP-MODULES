/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:00:39 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/02 18:01:02 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

ClapTrap::~ClapTrap( void )
{ 
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

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
	std::cout << this->_name
	<< " attacks " << target 
	<< ", causing " << this->_attackDamage << " points of damage!" 
	<< std::endl;
	this->_energyPoints--;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints += amount;
	std::cout << this->_name 
	<< " has been repaired for " << amount << " points!" 
	<< std::endl;
	this->_energyPoints--;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints -= amount;
	std::cout << this->_name 
	<< " has taken " << amount << " points of damage!" 
	<< std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs )
{
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

