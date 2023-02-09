/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:38:29 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:44:13 by ccambium         ###   ########.fr       */
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

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}
