/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:00:26 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/05 18:56:17 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		int				toInt( void ) const;
		float			toFloat( void ) const;
		Fixed 			&operator=(const Fixed &nb);
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

std::ostream 	&operator<<(std::ostream &, const Fixed &);
#endif
