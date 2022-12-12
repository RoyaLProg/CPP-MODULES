/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:43:30 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/02 09:00:51 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ){ return ; }

Harl::~Harl( void ){ return ; }

void	Harl::complain( std::string& level )
{
	void	(Harl::*complaint[])( void ) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};
	std::string complaintLevels[] = {
		"debug",
		"info",
		"warning",
		"error"
	};

	for (int i = 0; i < 4; i++)
	{
		void (Harl::*selectedComplaint)( void ) = complaint[i];
		if (level == complaintLevels[i])
		{
			(this->*selectedComplaint)();
			return ;
		}
	}
	std::cout << "Invalid complaint level" << std::endl;
}

void	Harl::_debug( void )
{
	std::cout << "[DEBUG] I love having extra bacon for my\
 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put\
 enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[WARNING]  think I deserve to have some extra bacon for free. I’ve been coming for\
 years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}
