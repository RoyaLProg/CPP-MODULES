/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:00:55 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/06 11:25:47 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data{
	public:
		Data();
		~Data();
		Data(std::string const &);
		Data(Data const & src);

		std::string & getSomeValue(void);
		
		Data & operator=(Data const &);
		bool operator==(Data const & rhs) const;
	private:
		std::string	_someValue;
};

#endif
