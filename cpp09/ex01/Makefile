# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 06:17:40 by ccambium          #+#    #+#              #
#    Updated: 2023/03/15 06:38:41 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS= -Werror -Wall -Wextra -std=c++98
CXX=c++
SRCS=main.cpp\
	RPN.cpp
NAME=RPN
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
