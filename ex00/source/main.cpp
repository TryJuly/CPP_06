/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:08:53 by strieste          #+#    #+#             */
/*   Updated: 2026/03/24 08:41:55 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error argument missing" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}

// int main(void)
// {
// 	std::cout << "###	Test 'a'	###" << std::endl;
// 	ScalarConverter::convert("'a'");
// 	std::cout << std::endl;

// 	std::cout << "###	Test int 42	###" << std::endl;
// 	ScalarConverter::convert("42");
// 	std::cout << std::endl;

// 	std::cout << "###	Test int -42	###" << std::endl;
// 	ScalarConverter::convert("-42");
// 	std::cout << std::endl;

// 	std::cout << "###	Test int 0	###" << std::endl;
// 	ScalarConverter::convert("0");
// 	std::cout << std::endl;

// 	std::cout << "###	Test int overflow	###" << std::endl;
// 	ScalarConverter::convert("99999999999999999");
// 	std::cout << std::endl;

// 	std::cout << "###	Test float normal	###" << std::endl;
// 	ScalarConverter::convert("4.2f");
// 	std::cout << std::endl;

// 	std::cout << "###	Test float negatif	###" << std::endl;
// 	ScalarConverter::convert("-4.2f");
// 	std::cout << std::endl;

// 	std::cout << "###	Test float zero	###" << std::endl;
// 	ScalarConverter::convert("0.0f");
// 	std::cout << std::endl;

// 	std::cout << "###	Test double normal	###" << std::endl;
// 	ScalarConverter::convert("4.2");
// 	std::cout << std::endl;

// 	std::cout << "###	Test double negatif	###" << std::endl;
// 	ScalarConverter::convert("-4.2");
// 	std::cout << std::endl;

// 	std::cout << "###	Test pseudo literal +inff	###" << std::endl;
// 	ScalarConverter::convert("+inff");
// 	std::cout << std::endl;

// 	std::cout << "###	Test pseudo literal nan	###" << std::endl;
// 	ScalarConverter::convert("nan");
// 	std::cout << std::endl;

// 	std::cout << "###	Test pseudo literal -inf	###" << std::endl;
// 	ScalarConverter::convert("-inf");
// 	std::cout << std::endl;

// 	return (0);
// }
