/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:28:07 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/19 15:09:45 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	/* An integer to store the fixed-point number value. */
	int _fixedPointValue;

	/*  A static constant integer to store the number of fractional bits.
	Its value will always be the integer literal 8. */
	static const int _fractionalBits = 8;

  public:
	Fixed(); // default constructor
	Fixed(const Fixed &rhs); // copy constructor.
	Fixed &operator=(const Fixed &rhs); // copy assignment operator overload.
	~Fixed(); // destructor

	/* A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value. */
	int getRawBits(void) const;
	/* A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number. */
	void setRawBits(int const raw);
};

#endif // FIXED_HPP
