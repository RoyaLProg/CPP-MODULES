/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:07:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 07:47:20 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 150);
	Form *form = new Form("Form", 1, 1);
	Form *form2 = new Form("Form2", 150, 150);
	
	
	bureaucrat->signForm(*form);
	bureaucrat2->signForm(*form);

	bureaucrat->signForm(*form2);
	bureaucrat2->signForm(*form2);

	try
	{
		Form *form3 = new Form("Form3", 0, 0);
		bureaucrat->signForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form *form3 = new Form("Form3", 151, 151);
		bureaucrat->signForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
