/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:19:00 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/12 15:27:11 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = "FragTrap";
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_name = name;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::attack( std::string const & target )
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0) { return ; }
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	FragTrap::takeDamage( unsigned int amount )
{
	if (this->_hitPoints <= 0) { return ; }
	std::cout << "FragTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void	FragTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints <= 0) { return ; }
	std::cout << "FragTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;
}

