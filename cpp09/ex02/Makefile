# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:18:41 by rkurnava          #+#    #+#              #
#    Updated: 2023/12/03 17:31:48 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

SRCS = main.cpp PmergeMe.cpp

all : $(NAME)

OBJS = $(SRCS:.cpp=.o)

$(OBJS) : ./PmergeMe.hpp

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@echo "Object files removed"

fclean : clean
	@rm -rf $(NAME)
	@echo "Executable removed"

re : fclean all

.PHONY : all clean fclean re
