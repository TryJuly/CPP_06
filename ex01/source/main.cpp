/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:20:48 by strieste          #+#    #+#             */
/*   Updated: 2026/04/01 15:15:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Serializer.hpp"
#include <iostream>
# include <stdint.h>


int	main(void)
{
	Data	data;
	Data	*newData;
	uintptr_t	raw;

	data.str = "Hello World !";
	data.nbr = 42;

	raw = Serializer::serialize(&data);
	
	std::cout << "Origin string: " << data.str << std::endl;
	std::cout << "Origin nbr: " << data.nbr << std::endl;

	std::cout << std::endl;

	std::cout << "Serialize" << std::endl;
	newData = Serializer::deserialize(raw);

	std::cout << std::endl;

	std::cout << "New data string: " << (*newData).str << std::endl;
	std::cout << "New data nbr: " << (*newData).nbr << std::endl;

	std::cout << std::endl;

	std::cout << "###	Change value origine	###" << std::endl;
	data.str = "Bad timing !";
	data.nbr = 355;

	std::cout << std::endl;

	std::cout << "Origin string: " << data.str << std::endl;
	std::cout << "Origin nbr: " << data.nbr << std::endl;

	std::cout << std::endl;

	std::cout << "New data string: " << (*newData).str << std::endl;
	std::cout << "New data nbr: " << (*newData).nbr << std::endl;
	return (0);
}
