/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:37:26 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/02 16:19:47 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include  <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
{
	this->_name = "RobotomyRequestForm";
	this->_target = target;
	this->_gradeToExecute = 72;
	this->_gradeToSign = 45;
	this->_signed = false;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomization failed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
		this->_signed = rhs.getSigned();
		this->_target = rhs.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}


