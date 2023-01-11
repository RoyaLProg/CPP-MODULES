/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:19:50 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/11 12:36:02 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Array<int> a(5);
	Array<int> b;

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	b = a;

	a[2] = 42;
	
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
}
