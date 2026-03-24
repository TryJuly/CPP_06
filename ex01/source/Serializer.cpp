/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:10:21 by strieste          #+#    #+#             */
/*   Updated: 2026/03/23 15:20:33 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Serializer.hpp"

Serializer::Serializer() { return ; }
Serializer::Serializer(Serializer const &copy)
{
	(void)copy;
	return ;
}
Serializer::~Serializer() { return ; }

Serializer	&Serializer::operator=(Serializer const &copy)
{
	(void)copy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
