/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:13:13 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/19 17:14:59 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *animals[100];
	
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 100; i++)
	{ 
		std::cout << "animals[" << i << "]\t: " << animals[i]->getType() << "\t";
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	for (int i = 0; i < 100; i++) { delete animals[i]; }
	return 0;
}