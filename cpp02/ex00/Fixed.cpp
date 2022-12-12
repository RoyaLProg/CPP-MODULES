/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:01:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/05 14:46:58 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() { this->_fixedPointValue = 0; }

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed	&Fixed::operator=(const Fixed &nb)
{
	this->_fixedPointValue = nb.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const { return (this->_fixedPointValue); }

void	Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }
