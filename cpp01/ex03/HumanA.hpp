/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:06:38 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:07:14 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );
		void attack( void );
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif
