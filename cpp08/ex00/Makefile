# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 11:05:46 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/10 14:15:37 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

CXX = c++ -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp

all: $(NAME)

OBJ = $(SRC:.cpp=.o)

$(OBJ): ./easyfind.hpp


%.o : %.cpp
	$(CXX) -c $< -o $@

$(NAME) : $(OBJ)
		$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		@rm -f $(OBJ)
		@echo "Object files removed"
		
fclean : clean
		@rm -f $(NAME)
		@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re
