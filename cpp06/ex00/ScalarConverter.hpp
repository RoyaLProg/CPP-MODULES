/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:53:33 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/22 19:16:50 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>

class ScalarConverter
{
	public:
		static void	convert(std::string str);
	
	private:
		static void	c_to_other(std::string str);
		static void	i_to_other(std::string str);
		static void	f_to_other(std::string str);
		static void	d_to_other(std::string str);
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
};

#endif
