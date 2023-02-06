/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:38:29 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/06 14:36:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	if (!_type.compare("Cat"))
		std::cout << "Meow" << std::endl;
	else if(!_type.compare("Dog"))
		std::cout << "Woof" << std::endl;
	else
		std::cout << "Animal noise" << std::endl;
}
