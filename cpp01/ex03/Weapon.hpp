/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:03:10 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 11:03:26 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP	

# include <iostream>

class Weapon
{
	public:
		Weapon( std::string type );
		~Weapon( void );
		std::string const &getType( void );
		void setType( std::string type );
	private:
		std::string _type;
};

#endif
