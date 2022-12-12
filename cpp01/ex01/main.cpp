/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:47:28 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 10:53:27 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	Zombie *Horde = zombieHorde(5, "Random");
	for (int i = 0; i < 5; i++)
		Horde[i].announce();
	delete [] Horde;
	return (0);
}
