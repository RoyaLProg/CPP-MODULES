/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:34:01 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/13 18:53:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		virtual ~Animal();

		Animal & operator=(Animal const & rhs);

		std::string getType() const;
	protected:
		std::string _type;
};

#endif
