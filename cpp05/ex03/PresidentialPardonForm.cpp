/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:52:33 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/02 15:59:39 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	this->_name = "PresidentialPardonForm";
	this->_gradeToSign = 25;
	this->_gradeToExecute = 5;
	this->_signed = false;
	this->_target = "<target>";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
{
	this->_name = "PresidentialPardonForm";
	this->_gradeToSign = 25;
	this->_gradeToExecute = 5;
	this->_signed = false;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
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

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
