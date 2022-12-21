/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:47:48 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/21 23:17:28 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	const Fixed _x;
	const Fixed _y;

  public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point &operator=(const Point &rhs);

	Fixed getX() const;
	Fixed getY() const;
	Point sub_point(Point &a, Point &b) const;
	Point sub_point(const Point &a, const Point &b) const;
	Point operator-(const Point &rhs) const;
	Point operator-(Point &rhs) const;
	Point add_point(Point &a, Point &b) const;
	Point add_point(const Point &a, const Point &b) const;
	Point operator+(const Point &rhs) const;
	Point operator+(Point &rhs) const;
	static Point input_point();
};

std::ostream &operator<<(std::ostream &ostream, Point const &Point);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
