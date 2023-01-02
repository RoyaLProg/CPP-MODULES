/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:02:21 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/02 16:22:28 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern(void) {}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return (*this);
}

AForm * Intern::makeForm(std::string formName, std::string target)
{
	std::cout << "Intern creates " << formName << std::endl;
	if (formName == "robotomy request")
		return new RobotomyRequestForm(target);
	if (formName == "presidential pardon")
		return new PresidentialPardonForm(target);
	if (formName == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	std::cout << "The intern died from stress trying to create a from that soes not exist, Are you happy now ? :(" << std::endl;
	return nullptr;
}
