# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:30:37 by ccambium          #+#    #+#              #
#    Updated: 2023/02/14 18:08:42 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS= -Werror -Wall -Wextra
CXX=c++
SRCS=AForm.cpp\
	Bureaucrat.cpp\
	Intern.cpp\
	main.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	ShrubberyCreationForm.cpp
NAME=Bureaucrat
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
