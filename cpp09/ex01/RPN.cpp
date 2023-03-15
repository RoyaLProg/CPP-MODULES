/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:19:00 by ccambium          #+#    #+#             */
/*   Updated: 2023/03/15 07:37:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::deque<char>	RPN::_operation;
bool				RPN::_failed = false;
bool				RPN::_loaded = false;


void	RPN::load(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ')
			continue ;
		_operation.push_back(input[i]);
	}
	verification();
	_loaded = true;
}

bool	RPN::verification()
{
	size_t	i = 2;
	bool	f = true;
	if (_operation.size() == 1)
		return (true);
	if (_operation.size() == 2 || !std::isdigit(_operation[0]) || !std::isdigit(_operation[1]))
		f = false;
	for (; i < _operation.size() && f; i++)
	{
		if (i % 2 == 0)
		{
			if (_operation[i] != '*'
			&& _operation[i] != '/'
			&& _operation[i] != '+'
			&& _operation[i] != '-')
				f = false;
		}
		else
		{
			if (!std::isdigit(_operation[i]))
				f = false;
		}
	}
	if (_operation[i - 1] != '*'
	&& _operation[i - 1] != '/'
	&& _operation[i - 1] != '+'
	&& _operation[i - 1] != '-')
		f = false;
	if (f == false)
	{
		std::cout << "ERROR : incorect formating" << std::endl;
		return f;
		_failed = true;
	}
	return (true);
}

static size_t	makeOperation(size_t n1, size_t n2, char op)
{
	switch (op)
	{
	case '*':
		return (n1 * n2);
	case '+':
		return (n1 + n2);
	case '/':
		return (n1 / n2);
	default:
		return (n1 - n2);
	}
}

void	RPN::resolve()
{
	size_t	n1;
	size_t	n2;
	size_t	i;
	char	op;

	if (_failed)
	{
		std::cout << "ERROR: loading have failed !" << std::endl;
		return ; 
	}
	if (!_loaded)
	{
		std::cout << "ERROR: not loaded !" << std::endl;
		return ; 
	}

	n1 = _operation[0] - '0';
	n2 = _operation[1] - '0';
	op = _operation[2];
	i = 3;
	for (; i < _operation.size(); i += 2)
	{
		n1 = makeOperation(n1, n2, op);
		n2 = _operation[i] - '0';
		op = _operation[i + 1];
	}
	n1 = makeOperation(n1, n2, op);
	std::cout << n1 << std::endl;
}
