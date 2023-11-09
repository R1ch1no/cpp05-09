# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 18:14:25 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/07 17:20:07 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializator

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

INCLUDES1 = ./Serializer.hpp

all: $(NAME)

SRC1 = main.cpp

SRC2 = Serializer.cpp

OBJ1 = $(SRC1:.cpp=.o)

OBJ2 = $(SRC2:.cpp=.o)

$(OBJ1):$(INCLUDES1)

$(OBJ2):$(INCLUDES1)

$(NAME): $(OBJ1) $(OBJ2)
	$(CXX) $(CXXFLAGS) $(OBJ1) $(OBJ2) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ1) $(OBJ2)
	@echo "Object files removed"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re
