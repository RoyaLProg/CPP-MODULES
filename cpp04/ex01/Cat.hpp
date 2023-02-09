/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:03:58 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/09 07:42:53 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain _brain;
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();
		Cat &operator=(const Cat & rhs);
	private:
		Brain * Brain;
};

#endif
