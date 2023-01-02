/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:05:49 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 08:26:43 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::~AForm(void) {}

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::ostream	& operator<<(std::ostream & o, AForm const & rhs)
{
	o << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() 
	<< ", form grade to execute " << rhs.getGradeToExecute() << ", form is signed " 
	<< rhs.getSigned() << std::endl;
	return (o);
}

std::string	AForm::getName(void) const { return (_name); }

int			AForm::getGradeToSign(void) const { return (_gradeToSign); }

int			AForm::getGradeToExecute(void) const { return (_gradeToExecute); }

bool		AForm::getSigned(void) const { return (_signed); }

std::string	AForm::getTarget(void) const { return (_target); }

void		AForm::beSigned(Bureaucrat const & rhs)
{
	if (rhs.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}
