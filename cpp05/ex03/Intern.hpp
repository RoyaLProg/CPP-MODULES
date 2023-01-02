/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:01:50 by ccambium          #+#    #+#             */
/*   Updated: 2023/01/02 16:04:05 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);
		Intern & operator=(Intern const & rhs);
		AForm * makeForm(std::string formName, std::string target);
};

#endif
