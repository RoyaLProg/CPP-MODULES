/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:14:48 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/07 13:20:17 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	ClapTrap1("ClapTrap1");
	ClapTrap	*ClapTrap2 = new ClapTrap(ClapTrap1);
	ClapTrap	ClapTrap3;

	delete	ClapTrap2;
	ClapTrap3 = ClapTrap1;
	ClapTrap1.attack("ClapTrap2");
	ClapTrap1.beRepaired(5);
	ClapTrap1.takeDamage(15);
	
	//clap trap has no more hit points
	ClapTrap1.attack("ClapTrap2");
	ClapTrap1.beRepaired(5);
	ClapTrap1.takeDamage(15);
	
	return (0);
}
