/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:53:55 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:43:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain _brain;
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();
		Dog & operator=(const Dog &rhs);
	private:
		Brain * Brain;
};

#endif
