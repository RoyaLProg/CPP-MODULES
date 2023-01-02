/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:35:10 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 08:27:44 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

# include "AForm.hpp"

class	Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(AForm &);
		void		executeForm(AForm const & form);
		
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

	private:
		Bureaucrat(void);

		std::string const	_name;
		int					_grade;
};

std::ostream	& operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
