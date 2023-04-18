/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:19:00 by ccambium          #+#    #+#             */
/*   Updated: 2023/04/18 14:11:13 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

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
		std::cout << "ERROR : incorrect formating" << std::endl;
		_failed = true;
		return f;
	}
	return (true);
}

std::ostream &operator<<(std::ostream &o, std::deque<double> d) {
	for (std::deque<double>::iterator it = d.begin(); it < d.end(); it++)
		o << *it << " ";
	o << "\n";
	return o;
}

static void	makeOperation(std::deque<double> *stack, char op)
{
	double result = 0;
	std::cout << *stack;
	double n2 = stack->front();
	stack->pop_front();
	double n1 = stack->front();
	stack->pop_front();
	std::cout << "operation : " << op << "\n";
	switch (op)
	{
		case '*':
			result = n1 * n2;
			break ;
		case '+':
			result = n1 + n2;
			break ;
		case '/':
			result = n1 / n2;
			break ;
		default:
			result = n1 - n2;
			break ;
	}
	std::cout << "result : " << result << "\n";
	stack->push_front(result);
}

int    decide(std::deque<double> *stack, char c)
{
    if (isdigit(c))
	{
		char number[2];
		number[0] = c;
		number[1] = '\0';
        stack->push_front(std::atof(&number[0]));		
	}
    else
	{
		if (stack->size() < 2)
			return (1);
		makeOperation(stack, c);
	}
	return (0);
}

void	RPN::resolve()
{
	std::deque<double> stack;
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
    if (_operation.size() == 1 && isdigit(_operation[0]))
    {
        std::cout << _operation[0] - '0' << "\n";
        return ;
    }
	else if (_operation.size() == 1){
		std::cout << "ERROR: operation only containing an operation ...";
		return;
	}
	for (size_t i = 0; i < _operation.size(); i ++)
	{
		if (decide(&stack, _operation[i]))
		{
			std::cout << "ERROR: something was not right !" << std::endl;
			return ;
		}
	}
	if (stack.size() != 1)
	{
		std::cout << "ERROR: missing an operation ...\n";
		return ;
	}
    std::cout << std::fixed << stack.front() << std::endl;
}
