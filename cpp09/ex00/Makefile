# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 19:18:25 by rkurnava          #+#    #+#              #
#    Updated: 2023/11/16 09:44:01 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp BitcoinExchange.cpp

INCLUDES = BitcoinExchange.hpp

OBJ = $(SRCS:.cpp=.cpp.o)

$(OBJ): $(INCLUDES)

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

%.cpp.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:	
	@rm -f $(OBJ)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re
