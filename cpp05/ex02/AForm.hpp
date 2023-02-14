/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:50:34 by ccambium          #+#    #+#             */
/*   Updated: 2023/02/14 18:08:29 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class 	Bureaucrat;

# include "Bureaucrat.hpp"

class	AForm{

	protected:
		std::string		_name;
		bool			_signed;
		int				_gradeToSign;
		int				_gradeToExecute;
		std::string		_target;
	
	public:
		virtual void			beSigned(Bureaucrat const &bureaucrat);
		virtual std::string		getName(void) const;
		virtual bool			getSigned(void) const;
		virtual int				getGradeToSign(void) const;
		virtual int				getGradeToExecute(void) const;
		virtual void			execute(Bureaucrat const &executor) const = 0;
		virtual std::string		getTarget(void) const;

		virtual ~AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	AForm &operator=(AForm const &rhs);
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
