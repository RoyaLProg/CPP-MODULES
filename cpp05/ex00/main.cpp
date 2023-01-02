/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:07:43 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/24 12:21:09 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Bureaucrat2", 150);
	
	std::cout << *bureaucrat;
	std::cout << *bureaucrat2;
	
	try 
	{ 
		Bureaucrat *bureaucrat3 = new Bureaucrat("Bureaucrat3", 0); 
		std::cout << *bureaucrat3;
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	
	try 
	{ 
		Bureaucrat *bureaucrat4 = new Bureaucrat("Bureaucrat4", 151);
		std::cout << *bureaucrat4;
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }

	try
	{
		bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bureaucrat2->decrementGrade();
		std::cout << *bureaucrat2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	delete bureaucrat;
	delete bureaucrat2;
	return (0);
}
