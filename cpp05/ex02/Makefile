# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkurnava <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 16:08:52 by rkurnava          #+#    #+#              #
#    Updated: 2023/10/31 15:48:55 by rkurnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES1 = ./AForm.hpp

INCLUDES2 = ./Bureaucrat.hpp

INCLUDES3 = ./PresidentialPardonForm.hpp

INCLUDES4 = ./RobotomyRequestForm.hpp

INCLUDES5 = ./ShrubberyCreationForm.hpp

all : $(NAME)

SRC1 = main.cpp

SRC2 = AForm.cpp

SRC3 = Bureaucrat.cpp

SRC4 = PresidentialPardonForm.cpp

SRC5 = RobotomyRequestForm.cpp

SRC6 = ShrubberyCreationForm.cpp

OBJ1 = $(SRC1:.cpp=.o)

OBJ2 = $(SRC2:.cpp=.o)

OBJ3 = $(SRC3:.cpp=.o)

OBJ4 = $(SRC4:.cpp=.o)

OBJ5 = $(SRC5:.cpp=.o)

OBJ6 = $(SRC6:.cpp=.o)

$(OBJ1):$(INCLUDES1) $(INCLUDES2) $(INCLUDES3) $(INCLUDES4) $(INCLUDES5)

$(OBJ2):$(INCLUDES1)

$(OBJ3):$(INCLUDES1) $(INCLUDES2)

$(OBJ4):$(INCLUDES1) $(INCLUDES3)

$(OBJ5):$(INCLUDES1) $(INCLUDES4)

$(OBJ6):$(INCLUDES1) $(INCLUDES5)


$(NAME): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
	$(CXX) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) *.form
	@echo "Cleaning done"

fclean : clean
	@rm -f $(NAME)
	@echo "Everything cleaned"

re : fclean all

.PHONY: all clean fclean re