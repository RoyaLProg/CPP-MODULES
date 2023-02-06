/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:11:17 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/06 14:25:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->Brain = new class Brain();
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->Brain = new class Brain(*(src.Brain));
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete Brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	delete	Brain;
	this->Brain = new class Brain(*rhs.Brain);
	return (*this);
}
