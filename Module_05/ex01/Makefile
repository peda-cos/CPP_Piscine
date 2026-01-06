NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Form up, maggots!"

%.o: %.cpp Bureaucrat.hpp Form.hpp
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
