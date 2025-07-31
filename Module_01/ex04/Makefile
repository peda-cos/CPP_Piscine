# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:20:20 by peda-cos          #+#    #+#              #
#    Updated: 2025/07/31 15:56:42 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Sed is for losers 📝"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@rm -f $(OBJ)
	@echo "Object file cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
