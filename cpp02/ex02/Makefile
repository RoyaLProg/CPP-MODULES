# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 12:17:18 by ccambium          #+#    #+#              #
#    Updated: 2023/01/30 04:17:27 by ccambium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS= -Werror -Wall -Wextra -std=c++98
CXX=c++
SRCS=Fixed.cpp\
	main.cpp
NAME=Fixed
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
