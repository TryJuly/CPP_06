/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:44:33 by strieste          #+#    #+#             */
/*   Updated: 2026/04/08 14:50:59 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstdlib>
# include <stdint.h>
#include <iostream>
#include <limits>
// #include <limits.h>
#include <errno.h>
#include <iomanip>

class ScalarConverter
{
	public:
		static void	convert(std::string const &str);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();

		ScalarConverter&	operator=(ScalarConverter const &copy);
};

#endif
