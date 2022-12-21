/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:27:54 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/21 14:17:53 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	: _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
	: _fixedPointValue(n << _fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
	: _fixedPointValue(std::round(n * (1 << _fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	_fixedPointValue = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int Fixed::toInt() const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

//----------------- Comparison operators -----------------//

bool Fixed::operator>(const Fixed &rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

//------------------ Arithmetic operators ------------------//

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

//------------------ Increment/Decrement operators ------------------//

Fixed &Fixed::operator++(void)
{
	++_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_fixedPointValue++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	--_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_fixedPointValue--;
	return (tmp);
}

//----------------------- Max and Min ----------------------//

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}
