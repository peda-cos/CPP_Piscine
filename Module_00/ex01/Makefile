# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:20:20 by peda-cos          #+#    #+#              #
#    Updated: 2025/07/31 07:57:13 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SOURCES = PhoneBook.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)
	@echo "PHONEBOOK ready to use!"

%.o: %.cpp PhoneBook.hpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiling $<..."

clean:
	@rm -f $(OBJECTS)
	@echo "Object file cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
