/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:07:43 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/02 16:17:10 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern *intern = new Intern();
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	AForm *form = intern->makeForm("shrubbery creation", "Shrubbery");
	AForm *form2 = intern->makeForm("robotomy request", "Robotomy");
	AForm *form3 = intern->makeForm("presidential pardon", "Presidential");

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

	delete intern;
	delete bureaucrat;
	delete form;
	delete form2;
	delete form3;
	return (0);
}
