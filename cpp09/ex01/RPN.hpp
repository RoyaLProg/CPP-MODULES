/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:19:04 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 07:20:20 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>

class RPN{
	public:
		static void load(std::string);
		static void resolve();
	private:
		RPN();
		static std::deque<char> _operation;
		static bool	verification();
		static bool	_failed;
		static bool	_loaded;

};
