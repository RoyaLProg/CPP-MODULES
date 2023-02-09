/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:11:17 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:41:50 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
	{
	 	this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
