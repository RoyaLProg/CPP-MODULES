/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:05:49 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 08:12:28 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const & src) : _name(src.getName()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	this->_signed = src.getSigned();
}

Form::~Form(void) {}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		_signed = rhs.getSigned();
	}
	return (*this);
}

std::ostream	& operator<<(std::ostream & o, Form const & rhs)
{
	o << rhs.getName() << ", form grade to sign " << rhs.getGradeToSign() 
	<< ", form grade to execute " << rhs.getGradeToExecute() << ", form is signed " 
	<< rhs.getSigned() << std::endl;
	return (o);
}

std::string	Form::getName(void) const { return (_name); }

int			Form::getGradeToSign(void) const { return (_gradeToSign); }

int			Form::getGradeToExecute(void) const { return (_gradeToExecute); }

bool		Form::getSigned(void) const { return (_signed); }

void		Form::beSigned(Bureaucrat const & rhs)
{
	if (rhs.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
