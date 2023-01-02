/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:50:34 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 08:02:46 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form;
# include "Bureaucrat.hpp"
class	Form{

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	
	public:
		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		Form &operator=(Form const &rhs);
		~Form(void);
		
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
		
		void			beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
