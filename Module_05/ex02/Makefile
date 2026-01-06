NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -O2
SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
       ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Bureaucrat.hpp AForm.hpp \
          ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "No, you need form 28B, not 28C..."

%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

clean:
	@rm -f $(OBJS)
	@echo "Objects removed."

cfiles:
	@rm -rf *_shrubbery
	@echo "Files removed."

fclean: clean cfiles
	@rm -f $(NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean cfiles fclean re
