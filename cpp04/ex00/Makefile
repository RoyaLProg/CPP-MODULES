# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:22:52 by ccambium          #+#    #+#              #
#    Updated: 2023/02/06 13:58:05 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS= -Werror -Wall -Wextra -std=c++98
CXX=c++
SRCS=Animal.cpp\
	Dog.cpp\
	Cat.cpp\
	main.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp
NAME=Animal
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
