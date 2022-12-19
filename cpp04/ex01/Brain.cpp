/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:41:35 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/15 01:42:20 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

std::string *Brain::getIdeas()
{
	return (this->ideas);
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain created" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}
