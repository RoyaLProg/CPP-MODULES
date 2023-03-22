/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 05:06:54 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/17 08:26:27 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include <ctime>

class PMergeMe
{
	public:
		static void	load(char **);
		static void	execute();
	private:
		static void	mergeSort(std::list<size_t> &);
		static void	mergeSort(std::vector<size_t> &);
		static void	merge(std::vector<size_t> &, std::vector<size_t> &);
		static void	startChrono(clock_t *);
		static void	endChrono(clock_t *);
		static void	printTab( void );

		static std::list<size_t>	_list;
		static std::vector<size_t>	_vector;
		static bool					veritfication(char **);
		static bool					_failed;
		static size_t				_size; 
		PMergeMe( void );

		// DEBUG
		// static void	mergeSort(std::list<size_t> &l, size_t low, size_t high, std::string s);
		// static void	mergeSort(std::vector<size_t> &v, std::string s);
};

std::ostream &operator<<(std::ostream &o, std::list<size_t> &list);
std::ostream &operator<<(std::ostream &o, std::vector<size_t> &vector);
