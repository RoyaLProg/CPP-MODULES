/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:08:08 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/22 19:16:53 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);
	
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const & src);
};

#endif
