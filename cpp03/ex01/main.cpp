/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:14:48 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/12 16:23:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	ScavTrap1("ScavTrap1");
	ScavTrap	*ScavTrap2 = new ScavTrap(ScavTrap1);
	ScavTrap	ScavTrap3;

	delete	ScavTrap2;
	ScavTrap3 = ScavTrap1;
	ScavTrap1.attack("ScavTrap2");
	ScavTrap1.beRepaired(5);
	ScavTrap1.takeDamage(115);
	
	//clap trap has no more hit points
	ScavTrap1.attack("ScavTrap2");
	ScavTrap1.beRepaired(5);
	ScavTrap1.takeDamage(15);
	
	return (0);
}
