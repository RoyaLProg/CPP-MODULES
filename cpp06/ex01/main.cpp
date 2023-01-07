/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:57:31 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/06 11:30:01 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>
#include <string>

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main(void)
{
	Data *data = new Data("test");
	uintptr_t raw = serialize(data);
	Data *data2 = deserialize(raw);
	std::cout << "data: " << data << " " << data->getSomeValue() << std::endl;
	std::cout << "data2: " << data2 << " " << data2->getSomeValue() << std::endl;
	std::cout << "data == data2: " << (*data == *data2) << std::endl;

	delete data;
	return 0;
}
