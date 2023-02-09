/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:55:31 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:43:31 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	_brain = Brain();
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = src._brain;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->Brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		_brain = rhs._brain;
	}
	return *this;
}
