# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 16:23:19 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/15 17:58:44 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = mutantstack

SRCS = main.cpp

INCLUDES = ./MutantStack.hpp

all : $(NAME)

OBJ = $(SRCS:.cpp=.o)

$(OBJ) : $(INCLUDES)


$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@echo "Object files removed"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"

re : fclean all

.PHONY : all clean fclean re
