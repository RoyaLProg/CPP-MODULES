/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:01:17 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/12 15:14:20 by ccambium         ###   ########.fr       */
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

void	ScavTrap::attack( std::string const & target )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	std::cout << "ScavTrap " << this->_name
	<< " attacks " << target 
	<< ", causing " << this->_attackDamage << " points of damage!" 
	<< std::endl;
	this->_energyPoints--;
}

void	ScavTrap::beRepaired( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints += amount;
	std::cout << "ScavTrap " << this->_name 
	<< " has been repaired for " << amount << " points!" 
	<< std::endl;
	this->_energyPoints--;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	this->_hitPoints -= amount;
	std::cout << "ScavTrap " << this->_name 
	<< " has taken " << amount << " points of damage!" 
	<< std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}
