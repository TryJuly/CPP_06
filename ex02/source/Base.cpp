/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:05:41 by strieste          #+#    #+#             */
/*   Updated: 2026/03/23 17:57:31 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"

Base*	Base::generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	else
		return (new C);
}

void	Base::identify(Base* p)
{}

void	Base::identify(Base& p)
{}