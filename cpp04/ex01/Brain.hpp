/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:40:21 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/15 01:43:37 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>



class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		~Brain();
		Brain & operator=(const Brain &rhs);
		Brain(const Brain &src);
		std::string *getIdeas();
};
#endif
