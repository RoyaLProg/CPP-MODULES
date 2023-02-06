/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:55:31 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/06 14:24:58 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->Brain = new class Brain();
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->Brain = new class Brain(*(src.Brain));
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->Brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	delete	Brain;
	this->Brain = new class Brain(*rhs.Brain);
	return (*this);
}
