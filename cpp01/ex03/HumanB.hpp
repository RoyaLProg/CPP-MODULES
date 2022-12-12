/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:15:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:15:40 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		~HumanB( void );
		void attack( void );
		void setWeapon( Weapon &weapon );
	private:
		std::string _name;
		Weapon *_weapon;
};

#endif
