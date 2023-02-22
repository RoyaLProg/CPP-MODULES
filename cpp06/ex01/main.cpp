/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:57:31 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/22 19:17:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data("test");
	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "data: " << data << " " << data->getSomeValue() << std::endl;
	std::cout << "data2: " << data2 << " " << data2->getSomeValue() << std::endl;
	std::cout << "data == data2: " << (*data == *data2) << std::endl;

	delete data;
	return 0;
}
