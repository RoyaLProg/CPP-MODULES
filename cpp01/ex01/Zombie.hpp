/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:41:17 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/01 10:50:45 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );
		void setName( std::string name );
		void announce( void );
	private:
		std::string _name;
};

Zombie * zombieHorde( int N, std::string name );

#endif
