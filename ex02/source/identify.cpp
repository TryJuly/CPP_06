/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:18:16 by strieste          #+#    #+#             */
/*   Updated: 2026/03/24 11:05:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"
#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include <exception>
#include <iostream>

void	identify(Base* p)
{
	A	*aClass = dynamic_cast<A*>(p);
	if (aClass != NULL){
		std::cout << "Type of the object pointed to by p: A" << std::endl;
		return ;
	}
	B	*bClass = dynamic_cast<B*>(p);
	if (bClass != NULL){
		std::cout << "Type of the object pointed to by p: B" << std::endl;
		return ;
	}
	C	*cClass = dynamic_cast<C*>(p);
	if (cClass != NULL){
		std::cout << "Type of the object pointed to by p: C" << std::endl;
		return ;
	}
	else
		std::cout << "Type pointed by p is not one of this three type: 'A' 'B' 'C'" << std::endl;
	return ;
}

void	identify(Base& p)
{
	try
	{
		A	&aClass = dynamic_cast<A&>(p);
		(void)aClass;
		std::cout << "Type of the object pointed to by p: A" << std::endl;
		return ;
	}
	catch(const std::exception& e){
		try
		{
			B	&bClass = dynamic_cast<B&>(p);
			(void)bClass;
			std::cout << "Type of the object pointed to by p: B" << std::endl;
			return ;
		}
		catch(const std::exception& e){
			try
			{
				C	&cClass = dynamic_cast<C&>(p);
				(void)cClass;
				std::cout << "Type of the object pointed to by p: C" << std::endl;
				return ;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Type pointed by p is not one of this three type: 'A' 'B' 'C'" << std::endl;
				return ;
			}
		}
	}
	return ;
}