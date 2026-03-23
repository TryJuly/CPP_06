/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:13:13 by strieste          #+#    #+#             */
/*   Updated: 2026/03/23 14:29:43 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <errno.h>
#include <iomanip>

static bool	IsInt(std::string const &str);
static bool	IsChar(std::string const &str);
static bool	IsFloat(std::string const &str);
static bool	IsDouble(std::string const &str);
static bool	IsPseudoLiteral(std::string const &str);
static void	PrintPseudoLiteral(std::string const &str);
static void	PrintChar(std::string const &str);
static void	PrintInt(std::string const &str);
static void	PrintDouble(std::string const &str);
static void	PrintFloat(std::string const &str);

ScalarConverter::ScalarConverter()
{ return ; }

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	(void)copy;
	return ;
}

ScalarConverter::~ScalarConverter()
{ return ; }

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &copy)
{
	(void)copy;
	return (*this);
}

void	ScalarConverter::convert(std::string const &str)
{
	if (IsPseudoLiteral(str))
		PrintPseudoLiteral(str);
	else if (IsChar(str))
		PrintChar(str);
	else if (IsInt(str))
		PrintInt(str);
	else if (IsFloat(str))
		PrintFloat(str);
	else if (IsDouble(str))
		PrintDouble(str);
	else
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		std::cout << "Float: Impossible." << std::endl;
		std::cout << "Double: Impossible." << std::endl;
	}
	return ;
}

static bool	IsPseudoLiteral(std::string const &str)
{
	if (str == "-inf" || str == "+inf")
		return (true);
	if (str == "-inff" || str == "+inff")
		return (true);
	if (str == "nan" || str == "nanf")
		return (true);
	return (false);
}

static bool	IsChar(std::string const &str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

static bool	IsInt(std::string const &str)
{
	int	sign = 0;
	if (str.empty())
		return (false);
	if (str[0] == '+' || str[0] == '-')
		sign++;
	if (sign && str.length() == 1)
		return (false);
	for (int i = sign; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

static bool	IsFloat(std::string const &str)
{
	int	sign = 0;
	int length = str.length();
	if (str.empty() || str[length - 1] != 'f' || str.find('.') == std::string::npos)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		sign++;
	if (sign && length == 1)
		return (false);
	for (int i = sign; i < (length - 1) ; i++)
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (false);
	}
	return (true);
}

static bool	IsDouble(std::string const &str)
{
	int	sign = 0;
	int length = str.length();
	if (str.empty() || str.find('.') == std::string::npos)
		return (false);
	if (str[0] == '+' || str[0] == '-')
		sign++;
	if (sign && length == 1)
		return (false);
	for (int i = sign; i < length ; i++)
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (false);
	}
	return (true);
}

static void	PrintPseudoLiteral(std::string const &str)
{
	std::cout << "Char: Impossible." << std::endl;
	std::cout << "Int: Impossible." << std::endl;
	if (str == "nan" || str == "-inf" || str == "+inf")
		std::cout << "Float: " << str << "f" << std::endl;
	else
		std::cout << "Float: " << str << std::endl;
	if (str == "nanf" || str == "-inff" || str == "+inff")
	{
		std::string copy = str;
		copy.erase(copy.length() - 1);
		std::cout << "Double: " << copy << std::endl;
	}
	else
		std::cout << "Double: " << str << std::endl;
	return ;
}

static void	PrintChar(std::string const &str)
{
	char	charResult;
	int		intResult;
	float	floatResult;
	double	doubleResult;

	charResult = str[1];
	std::cout << "Char: '" << charResult << "'" << std::endl;
	intResult = static_cast<int>(charResult);
	std::cout << "Int: " << intResult << std::endl;
	floatResult = static_cast<float>(charResult);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
	doubleResult = static_cast<double>(charResult);
	std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;

	return ;
}

static void	PrintDouble(std::string const &str)
{
	float	floatResult;
	double	doubleResult;

	errno = 0;
	doubleResult = strtod(str.c_str(), NULL);

	if (errno == ERANGE)
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		std::cout << "Float: Impossible." << std::endl;
		std::cout << "Double: Impossible." << std::endl;
		return ;
	}
	if (doubleResult < 0 || doubleResult > 127)
		std::cout << "Char: Impossible." << std::endl;
	else if (!isprint(doubleResult))
		std::cout << "Char: Non displayable." << std::endl;
	else
	{
		char charResult = static_cast<char>(doubleResult);
		std::cout << "Char: '" << charResult << "'" << std::endl;
	}
	if (doubleResult > INT_MAX || doubleResult < INT_MIN)
		std::cout << "Int: Impossible." << std::endl;
	else
	{
		int intResult = static_cast<int>(doubleResult);
		std::cout << "Int: " << intResult << std::endl;
	}
	if (doubleResult > std::numeric_limits<float>::max())
		std::cout << "Float: +inff" << std::endl;
	else if (doubleResult < -std::numeric_limits<float>::max())
		std::cout << "Float: -inff" << std::endl;
	else
	{
		floatResult = static_cast<float>(doubleResult);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
	}
	std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
	return ;
}

static void	PrintFloat(std::string const &str)
{
	float	floatResult;
	double	doubleResult;

	errno = 0;
	doubleResult = strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		std::cout << "Float: Impossible." << std::endl;
		std::cout << "Double: Impossible." << std::endl;
		return ;
	}
	if (doubleResult <= std::numeric_limits<float>::max() && doubleResult >= -std::numeric_limits<float>::max())
	{
		floatResult = strtof(str.c_str(), NULL);
		if (floatResult < 0 || floatResult > 127)
			std::cout << "Char: Impossible." << std::endl;
		else if (!isprint(floatResult))
			std::cout << "Char: Non displayable." << std::endl;
		else
		{
			char charResult = static_cast<char>(floatResult);
			std::cout << "Char: '" << charResult << "'" << std::endl;
		}
		if (floatResult > INT_MAX || floatResult < INT_MIN)
			std::cout << "Int: Impossible." << std::endl;
		else
		{
			int intResult = static_cast<int>(floatResult);
			std::cout << "Int: " << intResult << std::endl;
		}
		std::cout << "Float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
		std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
	}
	else
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		if (doubleResult > std::numeric_limits<float>::max())
			std::cout << "Float: +inff" << std::endl;
		else if (doubleResult < -std::numeric_limits<float>::max())
			std::cout << "Float: -inff" << std::endl;
		std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
	}
	return ;
}

static void	PrintInt(std::string const &str)
{
	char	charResult;
	int		intResult;
	float	floatResult;
	double	doubleResult;

	errno = 0;
	doubleResult = strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		std::cout << "Float: Impossible." << std::endl;
		std::cout << "Double: Impossible." << std::endl;
		return ;
	}
	if (doubleResult <= INT_MAX && doubleResult >= INT_MIN)
	{
		intResult = atoi(str.c_str());
		if (intResult < 0 || intResult > 127)
			std::cout << "Char: Impossible." << std::endl;
		else if (!isprint(intResult))
			std::cout << "Char: Non displayable." << std::endl;
		else
		{
			charResult = static_cast<char>(intResult);
			std::cout << "Char: '" << charResult << "'" << std::endl;
		}
		std::cout << "Int: " << intResult << std::endl;
		floatResult = static_cast<float>(intResult);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
		doubleResult = static_cast<double>(intResult);
		std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
	}
	else
	{
		std::cout << "Char: Impossible." << std::endl;
		std::cout << "Int: Impossible." << std::endl;
		if (doubleResult > std::numeric_limits<float>::max())
		std::cout << "Float: +inff" << std::endl;
		else if (doubleResult < std::numeric_limits<float>::min())
			std::cout << "Float: -inff" << std::endl;
		else
		{
			floatResult = static_cast<float>(doubleResult);
			std::cout << "Float: " << std::fixed << std::setprecision(1) << floatResult << "f" << std::endl;
		}
		std::cout << "Double: " << std::fixed << std::setprecision(1) << doubleResult << std::endl;
	}
	return ;
}