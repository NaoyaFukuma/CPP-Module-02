/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:27:42 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/21 23:25:01 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int	main(void)
{

	std::cout << "\e[33mThe function bsp determines whether the point P is inscribed in the triangle (A,B,C).\e[m\n" << std::endl;
	std::cout << "Create A point" << std::flush;
	Point A = Point::input_point();
	std::cout << "Create B point" << std::flush;
	Point B = Point::input_point();
	std::cout << "Create C point" << std::flush;
	Point C = Point::input_point();
	std::cout << "Create P point" << std::flush;
	Point P = Point::input_point();


	std:: cout << "Point A : " << A << std::endl;
	std:: cout << "Point B : " << B << std::endl;
	std:: cout << "Point C : " << C << std::endl;
	std:: cout << "Point P : " << P << std::endl;
	if (bsp(A, B, C, P) == true)
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return (0);
}
