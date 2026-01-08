NAME = ex01
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Span.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Span"

%.o: %.cpp Span.hpp
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
