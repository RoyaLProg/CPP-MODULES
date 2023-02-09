/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:55:31 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:42:16 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->brain = rhs.brain;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
