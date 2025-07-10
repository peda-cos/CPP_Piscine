# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: peda-cos <peda-cos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 15:20:20 by peda-cos          #+#    #+#              #
#    Updated: 2025/07/10 16:50:08 by peda-cos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SOURCES = ./megaphone.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)
	@echo "AGORA TA TUDO MAIÚSCULO AAAAAAAAH!"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "To fazendo aqui, não me apresse..."

clean:
	@rm -f $(OBJECTS)
	@echo "Passando uma vassoura aqui..."

fclean: clean
	@rm -f $(NAME)
	@echo "Passando um pano aqui..."

re: fclean all

.PHONY: all clean fclean re
