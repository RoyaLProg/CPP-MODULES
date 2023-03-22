/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 05:06:52 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/17 08:38:35 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <cstdlib>

std::list<size_t>	PMergeMe::_list;
std::vector<size_t>	PMergeMe::_vector;
size_t				PMergeMe::_size;
bool				PMergeMe::_failed = false;

PMergeMe::PMergeMe()
{
}

static size_t tab_size(char **av)
{
	size_t i = 0;
	while (av[i])
		i++;
	return (i);
}

void	PMergeMe::load(char **av)
{
	clock_t	start;
	clock_t	end;

	if (!veritfication(av))
		return ;
	startChrono(&start);
	_size = tab_size(av);
	for (size_t i = 0; i < _size; i++)
	{
		_list.push_back(atoi(av[i]));
		_vector.push_back(atoi(av[i]));
	}
	endChrono(&end);
	std::cout << "Loading time: " << std::fixed << (end - start) / (double)CLOCKS_PER_SEC << "us" << std::endl;
}

void	PMergeMe::startChrono(clock_t *start)
{
	*start = clock();
}

void	PMergeMe::endChrono(clock_t *end)
{
	*end = clock();
}

void	PMergeMe::merge(std::vector<size_t> &left, std::vector<size_t> &right)
{
	size_t i = 0;
	size_t j = 0;
	
	while (i < right.size() && j < left.size())
	{
		if (left[j] < right[i])
			j++;
		else
			left.insert(left.begin() + j, right[i++]);
	}
	while (i < right.size())
		left.push_back(right[i++]);
}

void	PMergeMe::mergeSort(std::vector<size_t> &v)
{
	if (v.size() > 1)
	{
		size_t mid = v.size() / 2;
		std::vector<size_t> left(v.begin(), v.begin() + mid);
		std::vector<size_t> right(v.begin() + mid, v.end());
		mergeSort(left);
		mergeSort(right);
		merge(left, right);
		v = left;
	}
}


void	PMergeMe::mergeSort(std::list<size_t> &l)
{
	if (l.size() > 1)
	{
		size_t mid = l.size() / 2;
		std::list<size_t>::iterator it = l.begin();
		std::advance(it, mid);
		std::list<size_t> left = std::list<size_t>(l.begin(), it);
		std::list<size_t> right= std::list<size_t>(it, l.end());
		mergeSort(left);
		mergeSort(right);
		left.merge(right);
		l = left;
	}
}

bool	PMergeMe::veritfication(char **av)
{
	size_t	size = tab_size(av);
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
			{
				_failed = true;
				std::cout << "Error: " << av[i] << " is not a positive number" << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

void	PMergeMe::execute()
{
	clock_t lstart;
	clock_t lend;
	clock_t vstart;
	clock_t vend;
	double ltime;
	double vtime;
	
	if (_failed)
	{
		std::cout << "Error: load() had failed !" << std::endl;	
		return ;
	}

	std::cout << "Before :\t";
	printTab();
	startChrono(&lstart);
	mergeSort(_list);
	endChrono(&lend);
	startChrono(&vstart);
	mergeSort(_vector);
	endChrono(&vend);
	std::cout << "After :\t\t";
	printTab();
	
	vtime = (vend - vstart) / (double)CLOCKS_PER_SEC;
	ltime = (lend - lstart) / (double)CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _size << " elements with std::list : " << std::fixed << ltime << " su" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " << std::fixed << vtime << " su" << std::endl;
}

void	PMergeMe::printTab()
{
	if (_vector.size() > 5)
	{
		for (size_t i = 0; i < 4; i++)
			std::cout << _vector[i] << " ";
		std::cout << "[...]";
	}
	else
	{
		for (size_t i = 0; i < _vector.size(); i++)
			std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &o, std::list<size_t> &list)
{
	for (std::list<size_t>::iterator it = list.begin(); it != list.end(); it++)
		o << *it << " ";
	return (o);
}

std::ostream &operator<<(std::ostream &o, std::vector<size_t> &vector)
{
	for (std::vector<size_t>::iterator it = vector.begin(); it != vector.end(); it++)
		o << *it << " ";
	return (o);
}

// DEBUG FONTIONS

// void	PMergeMe::mergeSort(std::vector<size_t> &v, std::string s)
// {
// 	std::cout << s << v << std::endl;
// 	if (v.size() > 1)
// 	{
// 		size_t mid = v.size() / 2;
// 		std::vector<size_t> left(v.begin(), v.begin() + mid);
// 		std::vector<size_t> right(v.begin() + mid, v.end());
// 		mergeSort(left, "left: ");
// 		mergeSort(right, "right: ");
// 		merge(left, right);
// 		v = left;
// 	}
// }

// void	PMergeMe::mergeSort(std::list<size_t> &l, size_t low, size_t high, std::string s)
// {
// 	std::cout << s << l << std::endl;
// 	if (low < high)
// 	{
	// size_t mid = l.size() / 2;
	// std::list<size_t>::iterator it = l.begin();
	// std::advance(it, mid);
	// std::list<size_t> left = std::list<size_t>(l.begin(), it);
	// std::list<size_t> right= std::list<size_t>(it, l.end());
	// mergeSort(left);
	// mergeSort(right);
	// left.merge(right);
	// l = left;
// 	}
// }
