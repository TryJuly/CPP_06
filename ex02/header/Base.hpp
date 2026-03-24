/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:40:07 by strieste          #+#    #+#             */
/*   Updated: 2026/03/24 10:49:34 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>

class Base
{
	public:
		virtual	~Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
