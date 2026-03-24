/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:40:07 by strieste          #+#    #+#             */
/*   Updated: 2026/03/23 17:56:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class Base
{
	public:
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
