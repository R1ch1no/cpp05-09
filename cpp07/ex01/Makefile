# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:54:00 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/05 19:50:24 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES = ./iter.hpp

all: $(NAME)

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

$(OBJ) : $(INCLUDES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "Object files removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
