/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 04:55:48 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/06 15:21:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span	sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try { sp.addNumber(42); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	Span	sp2 = Span(5);
	sp2.addNumber(1);
	try{ std::cout << sp2.shortestSpan() << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl;}
	try{ std::cout << sp2.longestSpan() << std::endl; }
	catch (std::exception &e) { std::cout << e.what() << std::endl;}

	return (0);
}
