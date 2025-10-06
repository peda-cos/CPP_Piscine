# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:20:20 by peda-cos          #+#    #+#              #
#    Updated: 2025/10/05 23:50:56 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Conversion of scalar types"

%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -f $(OBJS)
	@echo "Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re
