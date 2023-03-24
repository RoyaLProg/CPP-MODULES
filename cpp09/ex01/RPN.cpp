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
	if (!verification())
    {
        _loaded = false;
        return ;
    }
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
		if (_operation[i] != '*'
		&& _operation[i] != '/'
		&& _operation[i] != '+'
		&& _operation[i] != '-'
		&& !std::isdigit(_operation[i]))
        {
			f = false;
            break ;
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
		_failed = true;
		return f;
	}
	return (true);
}

static double	makeOperation(double n1, double n2, char op)
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

void    decide(double * n1, double * n2, double * reminder, double * result, char c)
{
    if (isdigit(c))
    {
        if (*n1 == -1)
            *n1 = c - '0';
        else if(*n2 == -1)
            *n2 = c - '0';
        else
            throw std::invalid_argument("ERROR all buffers are full\n");
    }
    else
    {

        if (*n1 >= 0 && *n2 >= 0 && *reminder == -1)
        {
            *reminder = makeOperation(*n1, *n2, c);
            *n1 = -1;
            *n2 = -1;
        }
        else if (*n1 >= 0 && *n2 >= 0 && *reminder != -1)
        {
            *result += *reminder;
            *reminder = makeOperation(*n1, *n2, c);
            *n1 = -1;
            *n2 = -1;
        }
        else if (*n1 >= 0 && *n2 == -1 && *reminder != -1)
        {
            *reminder = makeOperation(*reminder, *n1, c);
            *n1 = -1;
            *n2 = -1;
        }
        else if (*n1 == -1 && *n2 == -1 && *reminder >= 0)
        {
            *result = makeOperation(*result, *reminder, c);
            *reminder = -1;
        }
        else
            throw std::invalid_argument("ERROR: nothing to make operation on !\n");
    }
}

void	RPN::resolve()
{
	double	n1, n2, reminder, result;

    n1 = -1;
    n2 = -1;
    reminder = -1;
    result = 0;

	if (_failed)
	{
		std::cout << "ERROR: loading had failed !" << std::endl;
		return ; 
	}
	if (!_loaded)
	{
		std::cout << "ERROR: not loaded !" << std::endl;
		return ; 
	}
    if (_operation.size() == 1)
    {
        std::cout << _operation[0] - '0' << "\n";
        return ;
    }
	for (size_t i = 0; i < _operation.size(); i ++)
	{
        decide(&n1, &n2, &reminder, &result, _operation[i]);
	}
    if (reminder != -1)
        result += reminder;
    std::cout << std::fixed << result << std::endl;
}
