# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:18:31 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/28 15:38:35 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME = RPN

 CXX = c++

 CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -pedantic

 SRCS = main.cpp RPN.cpp

 all : $(NAME)

 OBJS = $(SRCS:.cpp=.o)

 $(OBJS) : ./RPN.hpp

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
