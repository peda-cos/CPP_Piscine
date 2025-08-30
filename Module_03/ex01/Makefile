# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:20:20 by peda-cos          #+#    #+#              #
#    Updated: 2025/08/30 10:22:03 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Serena, my love!"

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@rm -f $(OBJS)
	@echo "Object file cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
