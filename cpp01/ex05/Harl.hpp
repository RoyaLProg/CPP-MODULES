/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 08:37:22 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/02 08:43:20 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		Harl( void );
		~Harl( void );

		void	complain( std::string& level);
	private:
		void	_warning( void );
		void	_error( void );
		void	_info( void );
		void	_debug( void );
};

#endif
