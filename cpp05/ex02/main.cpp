/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:07:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 19:35:08 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	ShrubberyCreationForm *form = new ShrubberyCreationForm("Shrubbery");
	RobotomyRequestForm *form2 = new RobotomyRequestForm("Robotomy");
	PresidentialPardonForm *form3 = new PresidentialPardonForm("Presidential");

	std::cout << *bureaucrat << std::endl;
	std::cout << *form << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;

	bureaucrat->signForm(*form);
	bureaucrat->signForm(*form2);
	bureaucrat->signForm(*form3);

	bureaucrat->executeForm(*form);
	bureaucrat->executeForm(*form2);
	bureaucrat->executeForm(*form3);

	delete bureaucrat;
	delete form;
	delete form2;
	delete form3;
	return (0);
}
