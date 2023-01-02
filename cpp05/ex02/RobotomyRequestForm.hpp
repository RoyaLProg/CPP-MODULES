/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:38:14 by ccambium          #+#    #+#             */
/*   Updated: 2022/12/29 20:02:36 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const &executor) const;
	
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
};

#endif
