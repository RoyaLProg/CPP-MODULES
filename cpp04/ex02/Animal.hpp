/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:34:01 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:44:41 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		virtual ~Animal();
		Animal();
		Animal(Animal const & src);

		Animal & operator=(Animal const & rhs);

		std::string getType() const;
		void makeSound() const;
	protected:
		std::string _type;
};

#endif
