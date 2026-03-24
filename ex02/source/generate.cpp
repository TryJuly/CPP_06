/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:17:03 by strieste          #+#    #+#             */
/*   Updated: 2026/03/24 11:05:59 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"
#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include <ctime>

Base*	generate(void)
{
	int random = std::rand() % 3;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	else
		return (new C);
}
