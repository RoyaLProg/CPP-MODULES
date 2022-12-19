/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:14:48 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/13 18:29:00 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	FragTrap	FragTrap1("FragTrap1");
	FragTrap	*FragTrap2 = new FragTrap(FragTrap1);
	FragTrap	FragTrap3;

	delete	FragTrap2;
	FragTrap3 = FragTrap1;
	FragTrap1.attack("FragTrap2");
	FragTrap1.beRepaired(5);
	FragTrap1.takeDamage(115);
	
	//clap trap has no more hit points
	FragTrap1.attack("FragTrap2");
	FragTrap1.takeDamage(15);
	FragTrap1.beRepaired(5);
	
	return (0);
}
