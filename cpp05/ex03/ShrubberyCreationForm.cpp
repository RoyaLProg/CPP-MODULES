	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:52:28 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/17 10:29:09 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	this->_signed = false;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
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

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	std::ofstream	out;
	std::string		fileName = this->_target + "_shrubbery";
	
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	
	out.open(fileName.c_str(), std::ios::out | std::ios::app);
	if (out.fail())
	{
		std::cout << "failled to open " << fileName << std::endl;
		return ;
	}

	out << "          &&& &&  & &&" << std::endl;
	out << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	out << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	out << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	out << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	out << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	out << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	out << "     &&     \\|||" << std::endl;
	out << "             |||" << std::endl;
	out << "             |||" << std::endl;
	out << "             |||" << std::endl;
	out << "       , -=-~  .-^- _" << std::endl;
	out << std::endl;
	out << "               ,@@@@@@@," << std::endl;
	out << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	out << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	out << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	out << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	out << "       |o|        | |         | |" << std::endl;
	out << "       |.|        | |         | |" << std::endl;
	out << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\"" << std::endl;

	out.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
