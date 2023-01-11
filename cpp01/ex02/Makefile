# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:11:53 by ccambium          #+#    #+#              #
#    Updated: 2023/01/11 12:12:13 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS= -Werror -Wall -Wextra
CXX=c++
SRCS=main.cpp
NAME=ex02
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@	

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
