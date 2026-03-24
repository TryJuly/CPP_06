/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 09:05:04 by strieste          #+#    #+#             */
/*   Updated: 2026/03/24 11:07:43 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"
#include <iostream>
#include <ctime>


int	main(void)
{
	Base	base;
	Base	*p1;
	Base	*p2;
	Base	*p3;

	std::srand(std::time(0));
	p1 = generate();
	p2 = generate();
	p3 = generate();

	Base	&p4 = *p1;
	Base	&p5 = *p2;
	Base	&p6 = *p3;

	std::cout << "Identify pointer: " << std::endl;
	
	identify(p1);
	identify(p2);
	identify(p3);
	
	std::cout << std::endl;

	std::cout << "Identify reference: " << std::endl;

	identify(p4);
	identify(p5);
	identify(p6);

	delete p1;
	delete p2;
	delete p3;
	return (0);
}