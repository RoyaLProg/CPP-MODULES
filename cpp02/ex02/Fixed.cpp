/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:01:01 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/30 04:30:43 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() { this->_fixedPointValue = 0; }

Fixed::Fixed(const Fixed &src) { *this = src; }

Fixed::~Fixed() { }

Fixed	&Fixed::operator=(const Fixed &nb)
{
	this->_fixedPointValue = nb.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const { return (this->_fixedPointValue); }

void	Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

Fixed::Fixed(const int n) { this->_fixedPointValue = n << this->_fractionalBits; }

Fixed::Fixed(const float n) { this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits)); }

Fixed	& Fixed::min(Fixed & a, Fixed & b) { return (a < b ? a : b); }

Fixed	& Fixed::max(Fixed & a, Fixed & b) { return (a < b ? b : a); }

Fixed	const & Fixed::min(Fixed const & a, Fixed const & b) { return (a < b ? a : b); }

Fixed	const & Fixed::max(Fixed const & a, Fixed const & b) { return (a < b ? b : a); }

float	Fixed::toFloat( void ) const
{
	int		power = 1 << this->_fractionalBits; // == 2 ** this->_fractionalBits
	float	result = (float)this->getRawBits() / power;

	return (result);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &nb)
{
	o << nb.toFloat();
	return (o);
}

int	Fixed::toInt( void ) const { return (this->_fixedPointValue >> this->_fractionalBits); }

Fixed	&Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp(*this);

	this->_fixedPointValue++;
	return (tmp);
}

Fixed	&Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp(*this);

	this->_fixedPointValue--;
	return (tmp);
}

bool	Fixed::operator>(const Fixed &nb) const { return (this->_fixedPointValue > nb.getRawBits()); }

bool	Fixed::operator<(const Fixed &nb) const { return (this->_fixedPointValue < nb.getRawBits()); }

bool	Fixed::operator>=(const Fixed &nb) const { return (this->_fixedPointValue >= nb.getRawBits()); }

bool	Fixed::operator<=(const Fixed &nb) const { return (this->_fixedPointValue <= nb.getRawBits()); }

bool	Fixed::operator==(const Fixed &nb) const { return (this->_fixedPointValue == nb.getRawBits()); }

bool	Fixed::operator!=(const Fixed &nb) const { return (this->_fixedPointValue != nb.getRawBits()); }

Fixed	Fixed::operator+(const Fixed &nb) 
{
	Fixed tmp(this->toFloat() + nb.toFloat());
	return (tmp); 
}

Fixed	Fixed::operator-(const Fixed &nb) 
{
	Fixed tmp(this->toFloat() - nb.toFloat());
	return (tmp); 
}

Fixed	Fixed::operator*(const Fixed &nb) 
{
	Fixed tmp(this->toFloat() * nb.toFloat());
	return (tmp); 
}

Fixed	Fixed::operator/(const Fixed &nb) 
{
	Fixed tmp(this->toFloat() / nb.toFloat());
	return (tmp); 
}

