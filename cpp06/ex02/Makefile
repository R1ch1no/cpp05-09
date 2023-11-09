# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 17:44:34 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/07 17:20:12 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = randominator

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES = ./BaseClass.hpp

all: $(NAME)

SRC1 = main.cpp

SRC2 = BaseClass.cpp

OBJ1 = $(SRC1:.cpp=.o)

OBJ2 = $(SRC2:.cpp=.o)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ1): $(INCLUDES)
$(OBJ2): $(INCLUDES)

$(NAME): $(OBJ1) $(OBJ2)
	$(CXX) $(CXXFLAGS) $(OBJ1) $(OBJ2) -o $(NAME)

clean:
	@rm -rf $(OBJ1) $(OBJ2)
	@echo "Object files removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"
	
re: fclean all

.PHONY: all clean fclean re
