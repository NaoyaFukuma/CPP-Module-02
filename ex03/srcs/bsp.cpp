/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:50:20 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/21 22:58:42 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <math.h>


bool	bsp(Point const A, Point const B, Point const C, Point const P)
{

	Point AB(B - A);
	Point BP(P - B);
	Point BC(C - B);
	Point CP(P - C);
	Point CA(A - C);
	Point AP(P - A);

	Fixed	c1;
	Fixed	c2;
	Fixed	c3;

	c1 = AB.getX() * BP.getY() - AB.getY() * BP.getX();
	c2 = BC.getX() * CP.getY() - BC.getY() * CP.getX();
	c3 = CA.getX() * AP.getY() - CA.getY() * AP.getX();
	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0))
		return true;
	return false;
}
